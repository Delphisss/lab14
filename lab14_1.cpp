#include <iostream>
#include <cmath>
using namespace std;
//วิธีที่คิดสั่นกว่านี้ แต่อันนี้จะทำให้เข้าใจมากกว่า อีกโ๕้ดจะประมาณ40บรรทัด แต่จะงงเลยเขียนอันนี้ให้
void stat(const double[],int,double[]); //const = ค่าคงที่ หมายถึงค่าที่อยู่ใน array อะมันจะไม่แก้ค่าในนั้น จะคงอยู่อยากนี้ให้คงอยู่อย่างนี้ ตลอดไปฟอเอเวอร์~~~~~~~~~

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);  //sizeofเอาไว้หาจำนวนสมาชิกในarray
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0]; //ค่าเฉลี่ยเลขคณิต
    cout << "\nStandard Deviation = " << B[1]; //ส่วนเบี่ยงเบนมาตรฐาน
    cout << "\nGeometric Mean = " << B[2]; // ค่าเฉลี่ยเรขาคณิต
    cout << "\nHarmonic Mean = " << B[3]; //ค่าเฉลี่ยฮาร์มอนิก
    cout << "\nMax = " << B[4]; //ค่าสูงสุด
    cout << "\nMin = " << B[5]; //ค่าต่ำสุด
    return 0;                   // จากตรงนี้พอจะเก็ทมั้ยเริ่มแรกต้องเขียนโค้ดหาวิธีคำนวณค่าต่างๆตามที่โจทย์ต้องการ วิธีง่ายๆก็เปิดสูตรคำนวณจากในเน็ตละมาแปรเป็นโค้ดโล้ดเลยคั้บ 
}
//ค่าเฉลี่ยเลขคณิต ผลรวมของสมาชิก หารด้วย จำนวนของสมาชิก
double M(const double s[],int n){
    double sum = 0;
    for(int i=0; i < n; i++){
        sum += s[i];
    }
    return sum/n;
}
//ส่วนเบี่ยงเบนมาตรฐาน รากที่ 2 ของ(ข้อมูล-ค่าฉลี่ยเลขคณิต)^2หารด้วยจำนวนสมาชิก
double SD(const double s[],int n){
    double sum = 0;
    double sd;
    for(int i = 0;i<n;i++){
        sum += pow(s[i],2);
    }
    sd = sqrt((sum/n)-(pow(M(s,n),2)));
    return sd;
}
// ค่าเฉลี่ยเรขาคณิต รากที่ N ของ(สมาชิก1*สมาชิก2*สมาชิก3...*สมาชิกN) N คือตำนวน ข้อมูลตัวที่ N
double GM(const double s[],int n){
    double x = 1;
    for(int i = 0;i<n;i++){
        x *= s[i];
    }
    return pow(x,(double)1/n);
}
//ค่าเฉลี่ยฮาร์มอนิก N หารด้วย (1/x1 + 1/x2 + 1/x3 + ... 1/xN) // xN คือจำนวน ข้อมูลตัวที่ N
double HM(const double s[],int n){
    double x = 0;
    for (int i = 0; i < n; i++)
        x = x + (double)1 / s[i];
 
    return (double)n/x;
}
//ค่าสูงสุด หาค่าสูงสุดในข้อมูลทำเป็นลูบวนๆเพื่อเอาไปเช็คค่า ตรงนี้ก๋องไม่ได้คิดเป็นสูตรฟังชั่น แต่ทำเป็นลูปวนเช็คหาค่าที่มากสุด เพราะถ้าหาจากสูตรฟังชั่นมันจะต้องใช้จากอนุพันธ์อันดับที่ 1 มาคิด ทำเป็นลูบจะง่ายกว่า
double Max(const double s[],int n){
    double max = s[0];
    for (int i = 0; i < n; i++)
        if(s[i]>max) max =s[i];
 
    return max;
}
//ค่าต่ำสุด เหมือนหาค่าสูงสุดเลย แต่ทำให้โค้ดหาตัวที่ต่ำสุดแทน 
double Min(const double s[],int n){
    double min = s[0];
    for (int i = 0; i < n; i++)
        if(s[i]<min) min =s[i];
 
    return min;
}


// ส่วนสูดท้ายเอาค่าที่คิดได้เอาไปส่งเก็บไว้เก็บไว้ใน arrya B[] (ตรงที่ B[6] นั้นแหละ)จะรีเทิร์นเข้าไปเก็บก็ได้มั้งไม่ได้ลอง แต่เอามาบัญญัติให้มันเท่ากันเลยก็ได้ 
void stat(const double A[],int N,double B[]){
    B[0] = M(A,N);
    B[1] = SD(A,N);
    B[2] = GM(A,N);
    B[3] = HM(A,N);
    B[4] = Max(A,N);
    B[5] = Min(A,N);
}

//Kong >w<