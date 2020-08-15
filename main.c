
#include <stdio.h>
#include <string.h>
char mul[1000];
//char final[1000];
char d[1000];
char rslt[1000];
char save[1000][1000];
int len_str(char a[]){
    int i;
    for(i=0;a[i]!=0;i++);
    return (i);
}
int add_zero(char a[],int i){
    int j=0;
    int len=len_str(a);
    while (i!=0){
        a[len+j]='0';
        i--;
        j++;
    }
    a[len+j]=0;
    return 0;
}
void Num(char a[],int b){
    int i;
    int j=0;
    for(i=0;i<b-len_str(a);i++){
        d[i]='0';
    }
    for(;i<b;i++){
        d[i]=a[j];
        j++;
    }
    d[i]=0;
}
//jame 2 adad ba arghame yeksan
void sum(char a[],char b[]){
    int i;
    int j=len_str(a);
    int carry=0;
    d[len_str(a)+1]=0;
    for (i=len_str(a)-1;i>=0;i--){
        d[j]=(((a[i]-'0')+(b[i]-'0')+carry)%10)+'0';
        if((a[i]-'0')+(b[i]-'0')+carry>=10){
            carry=1;
        }
        else{
            carry=0;
        }
        j--;
    }
    if(carry==1){
        d[0]='1';
    }
    else{
        d[0]='0';
    }
}
void Bigadd(char a[],char b[]){
    if(len_str(a)>=len_str(b)){
        Num(b,len_str(a));
        sum(a,d);
    }
    else{
        Num(a,len_str(b));
        sum(b,d);
    }
}
int bigmul(char a[],char b[]){
    int i;
    int j;
    int k=0;
    int len;
    int carry;
    if (len_str(a)>=len_str(b)){
        for(i=len_str(b)-1;i>=0;i--){
            len=len_str(a);
            carry=0;
            mul[len+1]=0;
            for (j=len_str(a)-1;j>=0;j--){
                mul[len]=((((b[i]-'0')*(a[j]-'0'))+carry)%10)+'0';
                carry=(((b[i]-'0')*(a[j]-'0')+carry)/10);
                len--;
            }
            mul[0]=carry+'0';
            add_zero(mul,len_str(b)-1-i);
            Bigadd(mul,rslt);
            strcpy(rslt,d);
            k++;
            
        }
    }
    else{
        for(i=len_str(a)-1;i>=0;i--){
            len=len_str(b);
            carry=0;
            mul[len+1]=0;
            for (j=len_str(b)-1;j>=0;j--){
                mul[len]=((((a[i]-'0')*(b[j]-'0'))+carry)%10)+'0';
                carry=(((a[i]-'0')*(b[j]-'0')+carry)/10);
                len--;
            }
            mul[0]=carry+'0';
            add_zero(mul,len_str(a)-1-i);
            Bigadd(mul,rslt);
            strcpy(rslt,d);
            k++;
            
        }
    }
    printf("%s\n",rslt);
    return 0;
}
int main(){
    rslt[0]='0';
    rslt[1]=0;
    int i=0;
    int c;
    char a[100];
    char b[100];
    while((c=getchar())!='\n'){
        a[i]=c;
        i++;
    }
    a[i]=0;
    i=0;
    while((c=getchar())!='\n'){
        b[i]=c;
        i++;
    }
    b[i]=0;
    bigmul(a,b);
    return 0;
}



















