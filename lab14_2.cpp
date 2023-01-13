#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y; 
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y; // s == brush size , x แกน x , y แกน y
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}
//นิยาม เอาไว้แสดง * ในช่องต่างๆตามค่าที่ใส่เข้าไป
void showImage(const bool x[][M]){
    for(int i=0 ;i < 72;i++) //ทำลูปเพื่อสร้าง - ด้านบน ใช้72 เพราะ ทันคือ70 +ขอบข้างๆ 2ด้าน == 72
    cout << "-"; 
    cout << "\n";
    //ตรงนี้เอาไว้แสดง * โดยใช้ลูปมาเช็ค
    for(int i=0 ;i < 30;i++){ 
        cout <<"|";
        for(int j=0;j < 70;j++){
            if(x[i][j] == 0) cout << " "; //ถ้าค่าที่ใส่ไป == 0 จบโปรแกรม
            else cout <<"*"; // ถ้าไม่ก็ให้เป็น * ตรงตำแหน่งที่แทนค่าลงไป
        }
        cout << "|"<<endl;
    }


    for(int i=0 ;i <72;i++) //ทำลูปเพื่อสร้าง - ด้านล่าง ใช้72 เพราะ ทันคือ70 +ขอบข้างๆ 2ด้าน == 72
    cout << "-";
    cout << "\n";
    
}
//นิยาม เอาค่าเดิมจาก ฟังก์ชั่นด้านบน มาอัพเดท โดยเอามาเก็บตำแหน่งล่าสุดที่ใส่ค่ามาไว้ s x y
void updateImage(bool aray[][M],int s,int x,int y){
    for(int i=0;i < 30;i++){  // (i,j) == เอาไว้ตรวจสอบรัศมีของพู่กัน ทำเป็น for เพื่อวนลูปปรับจุดของพู่กันเพื่ออัพเดทภาพ 
        for(int j=0;j < 70;j++){ // 30 70 คือขอบเขตของจอที่ใช้วาด อารมเหมือนพื้นที่กว้างยาวของกระดาษ
            if(sqrt(pow(i-x,2)+pow(j-y,2))<= s-1){ //สูตรนี้มาจากโจทย์ให้
                aray[i][j] = 10; // 10 ตรงนี้เป็น 1 2 3 4 5 6 อะไรก็ได้ที่ไม่ใช่ 0 เพราะว่า ไม่รู้เช่นกัน ลองละมันส่งผ่าน5555555555+
            }
        }
    }
}

//Kong >w<