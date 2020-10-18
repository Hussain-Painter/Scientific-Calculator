#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<ctype.h>
#define size 20
void arithmetic();
float s[size];int top=-1;
void push(float s[],float ele)
{
if (top>=size-1)
{printf("Overflow\n"); }
else
 {
 top++;
 s[top]=ele;
 }
}
float pop(float s[])
{
float ele;
if (top<=-1)
{printf("Underflow\n");}
 else
 {
 ele=s[top];
 top--;
 }
return ele;
}

void postfix(char exp[])
{
int i=0;
double op1,op2;
 while(exp[i]!='\0')
 {
  if (isdigit(exp[i]))
  push(s,(float) exp[i]-'0');
  else
  {
  op2=(double)pop(s);
  op1=(double)pop(s);
  double ans;
   switch (exp[i])
   {
   case '+':
   ans=op1+op2;
   break;
   case '-':
   ans=op1-op2;
   break;
   case '/':
   ans=op1/op2;
   break;
   case '*':
   ans=op1*op2;
   break;
   case '^':
   ans=pow(op1,op2);
   break;
   default:
   printf("Invalid operator");
   }
  push(s,(float)ans);
  }
 i++;
 }
printf("The value of the expression is:  %f\n",pop(s));
getch();
}
void code();
void binary();
void octal();
void decimal();
void hexadecimal();
int bin2dec(long int);
int oct2dec(int);
long dec2bin(int);
long oct2bin(int);
void bin2hex(long);
long hex2bin(char []);
int  hex2oct(long);
int hex2dec(char []);
int dec2oct(int);
void dec2hex(int);
void normal();
int main()
{
    int ch;
    char exp[20];
    int cont;
    start:
    system("cls");
    system("COLOR 90");
    printf("\t\t\t\t\t===========================\n");
    printf("\t\t\t\t\t   SCIENTIFIC CALCULATOR\n");
    printf("\t\t\t\t\t===========================\n");
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t|     1.Normal     |\t\t\t|     2.Base       |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n");
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t|  3.Postfix Eval. |\t\t\t|     4.Exit       |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n\n");
    printf("\t\t\t\t\t*****Enter your choice*****\n\t\t\t\t\t\t    ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
         arithmetic();
         goto start;
         break;
     case 2:
         code();
         goto start;
         break;
     case 3:
        postfix:
            system("cls");
        printf("\t\t\t\t\tEnter an expression\n\t\t\t\t\t");
        scanf("%s",exp);
        postfix(exp);
        printf("\t\t\t\t\t*****Enter 1 to continue with postfix*****\n\t\t\t\t\t\t    ");
        scanf("%d",&cont);
    if (cont==1)
        goto postfix;
        goto start;
        break;
     case 4:
        printf("THANK YOU!");
        exit(0);
     default:
        printf("\nInvalid choice\n");
        goto start;

    }
    getch();
    return 0;
}
void arithmetic()
{
    int ch;
    double op1,op2;
    int cont;
    arithmetic:
    system("cls");
    printf("\t\t\t\t\tArithmetic Unit\n");
    printf("\t\t\t\t\t1.Addition\n");
    printf("\t\t\t\t\t2.Subtraction\n");
    printf("\t\t\t\t\t3.Division\n");
    printf("\t\t\t\t\t4Multiplication\n");
    printf("\t\t\t\t\t5.Sine\n");
    printf("\t\t\t\t\t6.Cosine\n");
    printf("\t\t\t\t\t7.Tan\n");
    printf("\t\t\t\t\t8.Cosec\n");
    printf("\t\t\t\t\t9.Sec\n");
    printf("\t\t\t\t\t10.Cot\n");
    printf("\t\t\t\t\t11.Log\n");
    printf("\t\t\t\t\t12.Power\n");
    printf("\t\t\t\t\tEnter your choice\n\t\t\t\t\t");
    scanf("%d",&ch);
 switch(ch)
    {
    case 1:
        printf("\t\t\t\t\tEnter 2 operands\n\t\t\t\t\t");
        scanf("%lf %lf",&op1,&op2);
        printf("\n%lf\n",op1+op2);
        break;
    case 2:
        printf("\t\t\t\t\tEnter 2 operands\n\t\t\t\t\t");
    scanf("%lf %lf",&op1,&op2);
        printf("\n%lf\n",op1-op2);
        break;
        case 3:

        printf("\t\t\t\t\tEnter 2 operands\t\t\t\t\t");
    scanf("%lf %lf",&op1,&op2);
    printf("\n%lf\n",op1/op2);
        break;
        case 4:
        printf("\t\t\t\t\tEnter 2 operands\n\t\t\t\t\t");
    scanf("%lf %lf",&op1,&op2);
        printf("\n%lf\n",op1*op2);
        break;
        case 5:
            printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("%lf",sin(op1));
    break;
        case 6:
            printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("\n%lf\n",cos(op1));
    break;
    case 7:
    printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("\n%lf\n",tan(op1));
    break;
    case 8:
    printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("\n%lf\n",1.0/sin(op1));
    break;
    case 9:
    printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("\n%lf\n",1/cos(op1));
    break;
    case 10:
        printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("\n%lf\n",1/tan(op1));
    break;
    case 11:
        printf("\t\t\t\t\tEnter an operand\n\t\t\t\t\t");
    scanf("%lf",&op1);
    printf("\n%lf\n",log(op1));
    break;
    case 12:
        printf("\t\t\t\t\tEnter 2 operands\n\t\t\t\t\t");
    scanf("%lf %lf",&op1,&op2);
        printf("\n%lf\n",pow(op1,op2));
        break;
    default:
        printf("Invalid choice\n");
    }
    printf("\t\t\t\t\tEnter 1 to continue");
    scanf("%d",&cont);
    if (cont==1)
        goto arithmetic;
    getch();
}

void code()
{   int ch;
    int cont;
    code:
   system("cls");
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t|     1.Binary     |\t\t\t|     2.Octal      |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n");
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t|  3.Decimal       |\t\t\t|  4.Hexadecimal   |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n\n");
    printf("\t\t\t\t\t*****Enter your choice*****\n\t\t\t\t\t\t    ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:binary();
            break;
     case 2:
            octal();
            break;
      case 3:decimal();
             break;
       case 4:hexadecimal();
              break;
       default:
        printf("Wrong choice\n");
    }
    printf("\t\t\t\t\t*****Enter 1 to continue with base*****\n\t\t\t\t\t\t    ");
    scanf("%d",&cont);
    if (cont==1)
        goto code;
    getch();
}




void binary()
{
  int ch,r,cont;
  long n;
   binary:
  system("cls");
   printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t| 1.Binary->Octal  |\t\t\t|2.Binary->Decimal |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n");
    printf("\t\t\t\t\t ____________________\n");
    printf("\t\t\t\t\t |                  |\n");
    printf("\t\t\t\t\t |    3.Binary->    |\n");
    printf("\t\t\t\t\t |     Hexadecimal  |\n");
    printf("\t\t\t\t\t |__________________|\n");
    printf("\t\t\t\t\t*****Enter your choice*****\n\t\t\t\t\t\t    ");
    scanf("%d",&ch);

    switch(ch)
    {
          case 1:
           printf("\t\t\t\t\t*****Enter a binary number*****\n\t\t\t\t\t\t    ");
           scanf("%ld",&n);
           r=bin2dec(n);
           printf("The conversion is:%d\n",dec2oct(r));
           break;
          case 2:
              printf("\t\t\t\t\t*****Enter a binary number*****\n\t\t\t\t\t\t    ");
              scanf("%ld",&n);
              printf("The conversion is:%d\n",bin2dec(n));
              break;
          case 3:
              printf("\t\t\t\t\t*****Enter a binary number*****\n\t\t\t\t\t\t    ");
              scanf("%ld",&n);
              bin2hex(n);
              break;
          default:
            printf("Wrong choice\n");
    }
    printf("\t\t\t\t\t*****Enter 1 to continue with binary*****\n\t\t\t\t\t\t    ");
    scanf("%d",&cont);
    if (cont==1)
        goto binary;

}
void bin2hex(long n)
{
            int r;
            r=bin2dec(n);
            printf("The conversion is:");
            dec2hex(r);
}
int bin2dec(long n)
{

    int r,i=0;double sum=0;
    while (n!=0)
    {
      r=n%10;
      n/=10;
      sum+=r*pow(2.0,(double)i);
      i++;
    }
    return (int)sum;
}
void octal()
{
    int ch;
    int n;
    int cont;
    system("cls");
    octal:
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t| 1.Octal->Binary  |\t\t\t|2.Octal->Decimal  |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n");
    printf("\t\t\t\t\t ____________________\n");
    printf("\t\t\t\t\t |                  |\n");
    printf("\t\t\t\t\t |    3.Octal->     |\n");
    printf("\t\t\t\t\t |     Hexadecimal  |\n");
    printf("\t\t\t\t\t |__________________|\n");
    printf("\t\t\t\t\t*****Enter your choice*****\n\t\t\t\t\t\t    ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        printf("\t\t\t\t\t*****Enter an octal number*****\n\t\t\t\t\t\t    ");
        scanf("%d",&n);
        printf("The conversion is:%ld\n",oct2bin(n));break;
    case 2:
        printf("\t\t\t\t\t*****Enter an octal number*****\n\t\t\t\t\t\t    ");
        scanf("%d",&n);
        printf("The conversion is:%d\n",oct2dec(n));
        break;
    case 3:
        printf("\t\t\t\t\t*****Enter an octal number*****\n\t\t\t\t\t\t    ");
        scanf("%d",&n);
        bin2hex(oct2bin(n));
        break;
    default:
        printf("Wrong choice\n");
    }
    printf("\t\t\t\t\t*****Enter 1 to continue with octal*****\n\t\t\t\t\t\t    ");
    scanf("%d",&cont);
    if (cont==1)
        goto octal;
}
int oct2dec(int n)
{
    int dec_no=0,i=0;
        while (n!=0)
    {
        dec_no+=(int)(n%10)*pow(8.0,(double)i);
        n/=10;
        i++;
    }
  return dec_no;
}
long dec2bin(int n)
{
    long binno=0;
    int i=1;
    while (n!=0)
    {
        binno+=((n%2)*i);
        n/=2;
        i*=10;
    }
    return binno;
}
long oct2bin(int n)
{
    int r;
    r=oct2dec(n);
        return dec2bin(r);
}
void hexadecimal()
{
   int ch,cont;
   char hex[20];
   long bin;
   hexa:
   system("cls");
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t| 1.Hexadecimal->  |\t\t\t|  2.Hexadecimal   |\n");
    printf("\t\t\t|   Binary         |\t\t\t|    ->Octal       |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n");
    printf("\t\t\t\t\t ____________________\n");
    printf("\t\t\t\t\t |                  |\n");
    printf("\t\t\t\t\t |   3.Hexadecimal->|\n");
    printf("\t\t\t\t\t |     Decimal      |\n");
    printf("\t\t\t\t\t |__________________|\n");
    printf("\t\t\t\t\t*****Enter your choice*****\n\t\t\t\t\t\t    ");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:
         printf("\t\t\t\t\t*****Enter a hexadecimal number*****\n\t\t\t\t\t\t    ");
         scanf("%s",hex);
        printf("The conversion is:%ld\n",hex2bin(hex));
        break;
      case 2:
          printf("\t\t\t\t\t*****Enter a hexadecimal number*****\n\t\t\t\t\t\t    ");
           scanf("%s",hex);
          bin=hex2bin(hex);
          printf("The conversion is:%d\n",hex2oct(bin));
          break;
      case 3:
        printf("\t\t\t\t\t*****Enter a hexadecimal number*****\n\t\t\t\t\t\t    ");
        scanf("%s",hex);
        printf("The conversion is:%d\n",hex2dec(hex));
        break;
      default:
        printf("Invalid choice\n");

    }
    printf("\t\t\t\t\t*****Enter 1 to continue with hexadecimal*****\n\t\t\t\t\t\t    ");
    scanf("%d",&cont);
    if (cont==1)
        goto hexa;

}
long hex2bin(char hex[])
{
    long int bin, place;
    int i = 0;

    bin = 0ll;
    place = 0ll;
     for (i = 0; hex[i] != '\0'; i++) {
        bin = bin * place;
     switch (hex[i])
     {
        case '0':
            bin += 0;
            break;
        case '1':
            bin += 1;
            break;
        case '2':
            bin += 10;
            break;
        case '3':
            bin += 11;
            break;
        case '4':
            bin += 100;
            break;
        case '5':
            bin += 101;
            break;
        case '6':
            bin += 110;
            break;
        case '7':
            bin += 111;
            break;
        case '8':
            bin += 1000;
            break;
        case '9':
            bin += 1001;
            break;
        case 'a':
        case 'A':
            bin += 1010;
            break;
        case 'b':
        case 'B':
            bin += 1011;
            break;
        case 'c':
        case 'C':
            bin += 1100;
            break;
        case 'd':
        case 'D':
            bin += 1101;
            break;
        case 'e':
        case 'E':
            bin += 1110;
            break;
        case 'f':
        case 'F':
            bin += 1111;
            break;
        default:
            printf("Invalid hexadecimal input.");
        }

        place = 10000;
    }

    return bin;
}
int hex2oct(long bin)
{
    int octal, place;
    int rem, val;
    octal = 0ll;
    place = 0ll;
    place = 1;
        while (bin > 0)
        {
          rem = bin % 1000;
          switch (rem)
          {
            case 0:
            val = 0;
            break;
            case 1:
            val = 1;
            break;
            case 10:
            val = 2;
            break;
            case 11:
            val = 3;
            break;
           case 100:
            val = 4;
            break;
            case 101:
            val = 5;
            break;
            case 110:
            val = 6;
            break;
           case 111:
            val = 7;
            break;
        }
        octal = (val * place) + octal;
        bin /= 1000;
        place *= 10;
    }
    return octal;
}
int hex2dec(char hex[])
{
    int i;
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;

    for (i=len-1; i>=0; i--)
    {
      if (hex[i]>='0' && hex[i]<='9')
        {
            dec_val += (hex[i] - 48)*base;
           base = base * 16;
        }
       else if (hex[i]>='A' && hex[i]<='F')
        {
            dec_val += (hex[i] - 55)*base;
            base = base*16;
        }
    }

    return dec_val;
}
void decimal()
{
    int ch,n;
    int cont;
    decimal:
    system("cls");
    printf("\t\t\t____________________\t\t\t____________________\n");
    printf("\t\t\t|                  |\t\t\t|                  |\n");
    printf("\t\t\t| 1.Decimal->      |\t\t\t|  2.Decimal       |\n");
    printf("\t\t\t|   Binary         |\t\t\t|    ->Octal       |\n");
    printf("\t\t\t|__________________|\t\t\t|__________________|\n");
    printf("\t\t\t\t\t ____________________\n");
    printf("\t\t\t\t\t |                  |\n");
    printf("\t\t\t\t\t |   3.Decimal->    |\n");
    printf("\t\t\t\t\t |    Hexadecimal   |\n");
    printf("\t\t\t\t\t |__________________|\n");
    printf("\t\t\t\t\t*****Enter your choice*****\n\t\t\t\t\t\t    ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
       printf("\t\t\t\t\t*****Enter a Decimal number*****\n\t\t\t\t\t\t    ");
       scanf("%d",&n);
        printf("The conversion is:%ld\n",dec2bin(n));
        break;
    case 2:
        printf("\t\t\t\t\t*****Enter a Decimal number*****\n\t\t\t\t\t\t    ");
        scanf("%d",&n);
        printf("The conversion is:%d\n",dec2oct(n));
        break;
    case 3:
        printf("\t\t\t\t\t*****Enter a Decimal number*****\n\t\t\t\t\t\t    ");
        scanf("%d",&n);
        printf("The conversion is: ");
        dec2hex(n);
        break;
    default:
        printf("Wrong choice\n");

    }
    printf("\t\t\t\t\t*****Enter 1 to continue with decimal*****\n\t\t\t\t\t\t    ");
    scanf("%d",&cont);
    if (cont==1)
        goto decimal;
}
int dec2oct(int n)
{
    int octalNumber = 0,i= 1;
    while (n!= 0)
    {
        octalNumber+=(n%8)*i;
        n/= 8;
        i*= 10;
    }
    return octalNumber;
}
void dec2hex(int n)
{
    int temp;
    char hexaDeciNum[100];
    int i=0;
    while(n!=0)
    {
      temp= 0;
      temp = n % 16;
      if(temp < 10)
        {
            hexaDeciNum[i]=(temp + 48);
            i++;
        }
        else
        {
            hexaDeciNum[i]=(temp + 55);
            i++;
        }
     n = n/16;
    }
for(int j=i-1; j>=0; j--)
        printf("%c",hexaDeciNum[j]);
        printf("\n");
}


