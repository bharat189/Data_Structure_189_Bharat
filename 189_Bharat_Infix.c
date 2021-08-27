#include <stdio.h>
char expr[20];
char symbol='E';
int i, a, b, value=0;
int operand[12];
int dtop=-1 ;
char operator[10];
int rtop=-1,x;

void pushoperand(){

   dtop=dtop+1;

   operand[dtop]=value;

}

char pushoperator(){

   rtop=rtop+1;

   operator[rtop]=symbol;
   return 0;
}

int popoperand(){

   if(dtop==-1)
   {
      x=0;  
   }else{

      dtop=dtop-1;

   }
   return 0;
}

char popoperator(){

   if(rtop==-1)
   {
      x=0;
   }else{

      rtop=rtop-1;

   }
}

int evaluate(){

   //symbol=operator[rtop];

   switch(symbol){
      case '+':{
         value = a+b;
         pushoperand();
         break;}
      case '-':{
         value = a-b;
         pushoperand();
         break;}
      case '*':{
         value = a*b;
         pushoperand();
         break;}
      case '/':{
         value = a/b;
         pushoperand();
         break;}
      default:{
         printf("\n\n!!!!ERROR!!!!\n\n");

   }
}
}

void main(){
  
   printf("Enter expression (do not use ^ operator) : \n");
   scanf("%s", &expr);

   for (i=0; expr[i] != '\0'; i++){
      if (expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*' || expr[i]=='(' || expr[i]==')'){
         symbol=expr[i];
         if (rtop==-1){
            //symbol=expr[i];
            pushoperator();
         }else{
            if(expr[i]=='('){
               //symbol=expr[i];
               pushoperator();
            }else{
               if(expr[i]==')'){
                  while(operator[rtop] != '('){
                     b=operand[dtop];
                     popoperand();
                     a=operand[dtop] ;
                     popoperand();
                     symbol=operator[rtop] ;
                     popoperator();

                     evaluate();
                  }
                  popoperator();
               }else{
                  if(expr[i]=='*'|| expr[i]=='/'){
                     //symbol=expr[i];
                     pushoperator();
                  }else{
                     if(expr[i]=='+'|| expr[i]=='-'){                    
                        //symbol=expr[i];
                        pushoperator();
                     
                     }else{
                        continue;
                     }
                  }
               }
            }
         }
      }else{
       
         value=expr[i]-48;
        

         pushoperand();
      }
   }
   if(expr[i]=='+' || expr[i]=='-' || expr[i]=='/' || expr[i]=='*' || expr[i]=='(' || expr[i]==')'){
      i=0;
   }else{
   while(rtop != -1){

      b=operand[dtop];
      popoperand();
      a=operand[dtop];
      popoperand();
      symbol=operator[rtop] ;
      popoperator();
      evaluate();
   };

   printf("Evaluated expression is: %d ", operand[dtop]);
   scanf("%d",&i);
   }

}
