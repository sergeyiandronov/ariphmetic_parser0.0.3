#include <iostream>
#include <sstream>

using namespace std;

int main()

{   int n=0;
    double* P=(double*)malloc(sizeof(double));
    char* command=(char*)malloc(sizeof(char));
    string str;
    double b;
    char com;
    getline(cin, str);
    istringstream stream(str);
    stream >> *P;
    while (stream >> com)
    {switch(com) {
            case '+':
                if(stream >> b){
                	command=(char*)realloc(command,(n+1)*sizeof(char));
                	*(command+n)=com;
                }
                
                n++;
                P=(double*)realloc(P,(n+1)*sizeof(double));
                *(P+n)=b;
                break;
            case '-':
            if(stream >> b){
                	command=(char*)realloc(command,(n+1)*sizeof(char));
                	*(command+n)=com;
                }
                 n++;
                P=(double*)realloc(P,(n+1)*sizeof(double));
                *(P+n)=b;
                break;
            case '*':
                stream >> b;
                *(P+n) = (*(P+n)) * b;
               
               
                break;
            case '/':
                stream >> b;
               *(P+n) = (*(P+n)) /b;
                break;
            }
        }
        double rs=*P;
        for(int i=0;i<n+1;i++){
        	switch(*(command+i)){
        		case '+':
        		rs+=*(P+i+1); break;
        		case '-':
        		rs-=*(P+i+1); break;
        		
        	}
        }

    cout << rs;
    return 0;

}
