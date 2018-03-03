#include <iostream>
using namespace std;

struct stack{
    string info[];
    int top;
};

void push(stack &S, string x){
    S.top++;
    S.info[S.top] = x;
}

void pop(stack &S){
    S.info[S.top] = "0";
    S.top--;
}

int main()
{
    string s,token;
    int arr[100];
    stack S;
    S.top = 0;
    int top = 0;

    cout<<"-------------------------------------------"<<endl<<endl;
    cout<<"Masukkan Formula Logika Proposisi    : "<<endl<<endl;
    cout<<"-------------------------------------------"<<endl;
    getline(cin,s);
    int l = s.length();
    bool cek = true;
    int i = 0;
    while ((cek==true)&&(i<l))
    {
        if (s[i]==' ')
        {
            i = i+1;
        }
        else
        {
            switch(s[i])
            {
            case 'p' : top++; arr[top] = 1; break;
            case 'q' : top++; arr[top] = 1; break;
            case 'r' : top++; arr[top] = 1; break;
            case 's' : top++; arr[top] = 1; break;
            case '(' : top++; arr[top] = 9; break;
            case ')' : top++; arr[top] = 10; break;
            case 'i' :
                i = i+1;
                if (s[i]=='f')
                {
                    i = i+1;
                    if (s[i]=='f')
                    {
                        top++;
                        arr[top] = 8;
                    }
                    else if((s[i]==' ')||(i==l))
                    {
                        top++;
                        arr[top] = 6;
                    }
                    else
                    {
                        cek = false;
                    };
                }
                else
                {
                    cek = false;
                };
                break;
            case 'n' :
                i = i+1;
                if (s[i]=='o')
                {
                    i = i+1;
                    if (s[i]=='t')
                    {
                        top++;
                        arr[top] = 2;
                    }
                    else
                    {
                        cek = false;
                    };
                }
                else
                {
                    cek = false;
                };
                break;
            case 'a' :
                i = i+1;
                if (s[i]=='n')
                {
                    i = i+1;
                    if (s[i]=='d')
                    {
                        top++;
                        arr[top] = 3;
                    }
                    else
                    {
                        cek = false;
                    };
                }
                else
                {
                    cek = false;
                };
                break;
            case 'x' :
                i = i+1;
                if (s[i]=='o')
                {
                    i = i+1;
                    if (s[i]=='r')
                    {
                        top++;
                        arr[top] = 5;
                    }
                    else
                    {
                        cek = false;
                    };
                }
                else
                {
                    cek = false;
                };
                break;
            case 'o' :
                i = i+1;
                if (s[i]=='r')
                {
                    top++;
                    arr[top] = 4;
                }
                else
                {
                    cek = false;
                };
                break;
            case 't' :
                i = i+1;
                if (s[i]=='h')
                {
                    i = i+1;
                    if (s[i]=='e')
                    {
                        i = i+1;
                        if (s[i]=='n')
                        {
                            top++;
                            arr[top] = 7;
                        }
                        else
                        {
                            cek = false;
                        };
                    }
                    else
                    {
                        cek = false;
                    };
                }
                else
                {
                    cek = false;
                };
                break;
            default  : cek = false; break;
            }
            i = i+1;
        }
    }
    if ((cek==false)||(arr[1]==3)||(arr[1]==4)||(arr[1]==5)||(arr[1]==7)||(arr[1]==8)||(arr[1]==10)){
        cout<<"-------------------------------------------"<<endl;
        cout<<"Token : ";
        for(int j=1;j<=top;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        // yang tidak boleh di array pertama : and 3, or 4, xor 5, then 7, iff 8, ) 10
        cout<<"-------------------------------------------"<<endl;
        cout<<endl<<"HASIL          : TIDAK VALID"<<endl<<endl;
        cout<<"-------------------------------------------"<<endl;
    }else{
        // Stack
        push(S,"#");
        int i = 1;
        if ((arr[i]==2)||(arr[i]==1)){ // not & pqrs
            i++;
        }else if (arr[i]==6){ // if
            push(S,"6");
            i++;
        }else if (arr[i]==9){ // (
            push(S,"9");
            i++;
        }
        cek = true;
        while ((i<=top)&&(cek==true)){
            switch(arr[i])
            {
                case 1  : if ((arr[i-1]==1)||(arr[i-1]==10)){
                              cek = false;
                          }else{
                              i++;
                          }
                          break;
                case 2  : if ((arr[i-1]==1)||(arr[i-1]==10)){
                              cek = false;
                          }else{
                              i++;
                          }
                          break;
                case 3  : if ((arr[i-1]==1)||(arr[i-1]==10)){
                              i++;
                          }else{
                              cek = false;
                          }
                          break;
                case 4  : if ((arr[i-1]==1)||(arr[i-1]==10)){
                              i++;
                          }else{
                              cek = false;
                          }
                          break;
                case 5  : if ((arr[i-1]==1)||(arr[i-1]==10)){
                              i++;
                          }else{
                              cek = false;
                          }
                          break;
                case 6  : push(S,"6"); i++; break;
                case 7  : pop(S); i++; break;
                case 8  : if ((arr[i-1]==1)||(arr[i-1]==10)){
                              i++;
                          }else{
                              cek = false;
                          }
                          break;
                case 9  : push(S,"9"); i++; break;
                case 10 : pop(S); i++; break;
            }
        }
        cout<<"-------------------------------------------"<<endl;
        cout<<"Token : ";
        for(int j=1;j<=top;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        if ((S.info[S.top]=="#")&&(cek==true)){
            cout<<"-------------------------------------------"<<endl;
            cout<<endl<<"HASIL          : VALID"<<endl<<endl;
            cout<<"-------------------------------------------"<<endl;
        }else{
            cout<<"-------------------------------------------"<<endl;
            cout<<endl<<"HASIL          : TIDAK VALID"<<endl<<endl;
            cout<<"-------------------------------------------"<<endl;
        }
    }
    return 0;
}