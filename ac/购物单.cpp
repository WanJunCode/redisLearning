#include <iostream>
#include <string>
using namespace std;
  
int getMax(int x, int y){
    return (x > y ? x : y);
}

int main(){
    int N;  //总钱数
    int m;  //希望购买的物品个数
    int weight[60][3]={0};  //价格（成本）
    int value[60][3]={0};   //价值（重要度*价格）
    int f[60][3200];        //第i个物品在j容量下可以获得的最大价值
    int i,j;
  
    cin >> N >> m;
    N/=10;  //都是10的整数，先除以10，减少循环次数
    //存储清单
    for(int i=1;i<=m;i++){
        int v;  //该物品价格
        int p;  //该物品价值
        int q;  //该物品主件还是附件
        cin >> v >> p >> q;
        v/=10;
  
        if(q==0){               //主件
            weight[i][0]=v;
            value[i][0]=p*v;
        }
        else{                   //附件
            if(weight[i][1]==0){    //第一个附件
                weight[i][1]=v;
                value[i][1]=p*v;   
            }
            else{                   //第二个附件
                weight[i][2]=v;
                value[i][2]=p*v;
            }
        }
    }
    //遍历计算
    for(i=1;i<=m;i++){
        for(j=N;j>0;j--){
            if(j>=weight[i][0])      //可以容下第i个主件时,比较放第i个或者不放第i个物品的价值
                f[i][j]=getMax(f[i-1][j],f[i-1][j-weight[i][0]]+value[i][0]);
            if(j>=weight[i][0]+weight[i][1]) //可以容下第i个主件和此主件的第1个附件时
                f[i][j]=getMax(f[i-1][j],f[i-1][j-weight[i][0]-weight[i][1]]+value[i][0]+value[i][1]);
            if(j>=weight[i][0]+weight[i][2]) //可以容下第i个主件和此主件的第2个附件时
                f[i][j]=getMax(f[i-1][j],f[i-1][j-weight[i][0]-weight[i][2]]+value[i][0]+value[i][2]);
            if(j>=weight[i][0]+weight[i][1]+weight[i][2])        //可以容下第i个主件和此主件的第1个附件和第2个附件时
                f[i][j]=getMax(f[i-1][j],f[i-1][j-weight[i][0]-weight[i][1]-weight[i][2]]+value[i][0]+value[i][1]+value[i][2]);
        }
    }
    cout << f[m][N]*10 << endl;
}