#include <stdio.h>
int main() {
    int n;
    float capacity;
    printf("enter the number of item : ");
    scanf("%d",&n);
    printf("enter the capacity");
    scanf("%f",&capacity);
    float profit[n],weight[n],ratio[n];
    printf("enter the weight");
    for(int i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }
    printf("enter the profit");
    for(int i=0;i<n;i++){
        scanf("%f",&profit[i]);
        ratio[i]=profit[i]/weight[i];
    }
    float temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;
                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
    float tp=0.0;
    for(int i=0;i<n;i++){
        if (weight[i]<=capacity){
            tp+=profit[i];
            capacity-=weight[i];
        }
        else{
            tp+=capacity*ratio[i];
            break;
        }
    }
    printf("the total profit:%f",tp);
    return 0;
}
