#include <cstdio>

#include <iostream>

#include <string>

using namespace std;


int N, K;


void recur(int length,int used[], string str){


    if( K == 0 ) return;        //prunning extra branches


    if( length == N ){

        cout << str << endl;

        K--;

        return;

    }


    for(int i = 0; i < N; i++){

        if(!used[i]){


            string temp = str;

            temp +=  (char)(i+'A');

            used[i] = 1;
            cout<<"i="<<i<<" temp="<<temp<<" used["<<i<<"]="<<used[i]<<endl;
         	cout<<"recur("<<length+1<<","<<temp<<")"<<endl;
            recur(length+1, used, temp);
            used[i] = 0;
            cout<<"i="<<i<<" temp="<<temp<<" used["<<i<<"]="<<used[i]<<endl;

        }

    }

}


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

    int T;

    cin >> T;

    for(int c = 1; c <= T; c++){

        cin >> N >> K;


        int used[28];

        for(int j = 0; j < N; j++)

            used[j] = 0;

        cout << "Case " << c << ":" << endl;

        recur(0,used,"");

    }


}