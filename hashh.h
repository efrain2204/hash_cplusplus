#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <cstdlib>

/*graphiz*/
#include <stdlib.h>

using namespace std;

/*AUXILIARES*/
/*
bool random() {
    if (rand() % 2 == 0)
        return true;
    else
        return false;
}

*/

/*Nodo de listaaaaaaaaaa*/
class Nodo{
public:
    string cod,name;
    int saldo;
    Nodo* sig;
    Nodo(string c,string n ,int s):cod(c),name(n),saldo(s),sig(NULL) {};
    Nodo(string c,string n ,int s,Nodo* nd):cod(c),name(n),saldo(s),sig(nd) {};
};
/*Listaaaaaaaaaaaaaaaaa*/
class List{
public:
    Nodo *actual;
    List(){
        actual=NULL;
    }
    bool add_new(string cod,string name,int saldo){
        Nodo * aux= new Nodo(cod,name,saldo);
        Nodo * t;
    if(actual==NULL)
        actual = aux;
    else
    {
        t = actual;
        while(t->sig!=NULL)
        {
            t = t->sig;
        }
        t->sig = aux;
    }
    return true;
    }
    bool search(string n){
        Nodo* aux = actual;
        while(aux!=NULL){
            if(aux->name==n)return true;
        }
        return false;
    }
    void print(){
        Nodo *aux=actual;
        while(aux!=NULL){
            cout<<aux->cod<<endl;
            aux=aux->sig;
        }
    }
    vector<string> get() const
    {
        vector<string> str_vec;
        for(Nodo* temp=actual;temp!=NULL;temp=temp->sig)
            str_vec.push_back(temp->cod);
        return str_vec;
    }
};

/*Clase Hasssshhhhhhhhhhhh*/
class Hash{
public:
    List * arr;
    int arrSize;
    int numReg;

    void inicializar(int n){
        arrSize=getPrime(n);
        arr=new List[arrSize];
        numReg=0;
    }
    int maxSize() const
    {
        return arrSize;
    }
    int getCod(string cod){
        string tmp="";
        bool estado=false;
        for(int i = 0;i<cod.size();i++){
            if(cod[i]=='-'){
                estado=true;
            }
            if(estado)tmp=tmp+cod[i+1];
        }
        stringstream stream1(tmp);
        int x = 0;
    stream1 >> x;
    return x;

    }
    bool insert(string cod , string name,int saldo){
        int cd=getCod(cod);
        int hash=hashFunc(cd);

        bool successOrFail=arr[hash].add_new(cod,name,saldo);

        return successOrFail;
    }
    vector<string> get() const
    {
        vector<string> v,tmp_v;
        for(int i=0;i<maxSize();i++)
        {
            //cout<<i<<"  ";
            tmp_v=arr[i].get();
            for(int j=0;j<tmp_v.size();j++){
                //cout<<tmp_v[j]<<" ";
                v.push_back(tmp_v[j]);
            }
            //cout<<endl;
        }
        return v;
    }
    bool cargar(string name){
        cout<<name<<endl;

        string cod,nam;
        int saldo;
        ifstream file_(name.c_str());

        if (file_.is_open()) {
            while(file_>>cod>>nam>>saldo){
                numReg++;
                this->insert(cod,nam,saldo);
            }
            file_.close();
            return true;
        }else{
            return false;
        }
    }

    void display()const
    {
        ofstream out("out.gv");
        out << dot() << endl;
        out.close();
        system("dot.exe -Tpng out.gv -o out.png");
    }

private:

    void print_dot(ostream &out/*, Nodo* p*/)const
    {
        vector<string> v,tmp_v;
        for(int i=0;i<maxSize();i++)
        {
            out<<i<<"[label="<<i<<",fontcolor=black];\n";

            tmp_v=arr[i].get();
            cout<<"tamaño de array "<<i<<"-"<<tmp_v.size()<<endl;
            if(tmp_v.size()>0){
                cout<<"valor de array : "<<tmp_v[0]<<endl;
                out<<i<<" -> "<<tmp_v[0]<<"\n";
            }
            /*for(int j=0;j<tmp_v.size();j++){

                if(j <tmp_v.size())
                    out<<tmp_v[j] << " -> "<<tmp_v[j+1] << ";\n";

                //out<<tmp_v[j]<<" -> ";
            }*/

        }
        /*
        if(p != NULL)
        {
            static int cont=0;
            out << p->dato << "[label=" << p->dato << ",fontcolor=black];\n";
            if (p->left){
                out << p->dato << " -> "<< p->left->dato << ";\n";
                }
            else{
                cont++;
                out << "Nodo"<<cont<<"[label=null,fillcolor=skyblue,fontcolor=black];\n";
                out << p->dato << " -> "<< "Nodo"<<cont<<";\n";
            }
            if (p->right){
                out << p->dato << " -> "<< p->right->dato << ";\n";
            }
            else{
                cont++;
                out<< "Nodo"<<cont<<"[label=null,fillcolor=skyblue,fontcolor=black];\n";
                out << p->dato << " -> "<< "Nodo"<<cont<<";\n";
            }
            print_dot(out, p->left);
            print_dot(out, p->right);
        }*/

    }

    string dot()const
    {
        stringstream stm;
        stm << "digraph {\ node [shape=circle, style=filled]\n";
        print_dot(stm /*, root*/);
        stm << "}\n";
        return stm.str();
    }
    int getPrime(int n) const
    {
        int i=n;
        while(!isPrime(i))
            i++;
        return i;
    }

    bool isPrime(int n) const
    {
        bool isPrime=true;
            for(int count=2;count<n && isPrime; count++)
                if(n%count==0)
                    isPrime=false;
        return isPrime;
    }
    int hashFunc(int i) const
    {
        int aux=i % maxSize();
        return aux;
    }
};
/*
int main() {
    Hash h(30);
    h.cargar("read.txt");
    cout<<"Tamaño"<<h.maxSize()<<endl;
    vector<string> v1 = h.get();

    return 0;
}*/
