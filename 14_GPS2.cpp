#include <stdio.h>
#include <cmath>

double getyaw(double lng1, double lat1, double lng2, double lat2){
    //   C 语言里 double atan2(double y,double x) 返回的是原点至点(x,y)的方位角，即与 x 轴的夹角。返回值的单位为弧度，取值范围为（-π, π]。结果为正表示从 X 轴逆时针旋转的角度，结果为负表示从 X 轴顺时针旋转的角度。若要用度表示反正切值，请将结果再乘以 180/π。另外要注意的是，函数atan2(y,x)中参数的顺序是倒置的，atan2(y,x)计算的值相当于点(x,y)的角度值。
    // double PI = 3.1415926;
    // double x = sin(lng2 - lng1) * cos(lat2);
    // double y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lng2 - lng1);
    // double angle = atan2(x,y) * 180 / PI;
    
    double PI = 3.1415926;
    double x = lng2 - lng1;
    double y = lat2 - lat1;
    double angleR = atan2(y,x) ;
    double angleD = atan2(y,x) * 180 / PI;
    printf("  yaw D  %lf \n", angleD);
    printf("  yaw r  %lf \n", angleR);
    return angleR;
    // return angle>0?angle:angle+360;
}

void test(){
    getyaw(116, 39, 116  , 39  ); 
    // 东 东北 北 西北 西
    getyaw(116, 39, 116+1, 39  ); 
    getyaw(116, 39, 116+1, 39+1); 
    getyaw(116, 39, 116  , 39+1); 
    getyaw(116, 39, 116-1, 39+1); 
    getyaw(116, 39, 116-1, 39  ); 
    printf("\n");
    getyaw(116, 39, 116+1, 39-1); 
    getyaw(116, 39, 116  , 39-1); 
    getyaw(116, 39, 116-1, 39-1); 

}

int main() {
    test();
}

