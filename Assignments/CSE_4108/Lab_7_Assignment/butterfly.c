void delay(){
    for(int i=0;i<1000000;i++);
}


void butterfly(int n,char c,char alt){
	int i,j,k,f;
    int st=n-1;
    f=2*n-1;
    int s=n+1;
    for(k=1,i=1;i<2*n;i++,f--){
        for(j=1;j<2*n;j++){
            delay();
            if(i<=n){
               if(j<=n)
                    if(j<=i) printf("%c",c);else printf("%c",alt);      
                else if(j>n){
                     if(j<f) printf("%c",alt);else printf("%c",c);
               }            
            } else if(i>n){
                 delay();
                if(j<=n) if(j<=f) printf("%c",c);else printf("%c",alt);
                else if(j>n && j>=s) printf("%c",c);else printf("%c",alt);
            }
        }
        if(i>n) {
            st--;
            s++;
        }
        printf("\n");
    }
    printf("\n");
}