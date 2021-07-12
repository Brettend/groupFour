#include<iostream>
#include<string>
#include<cmath>
using namespace std;

void arrValues(int *&arr,int sentinel){

    int value;

    if(sentinel!=-1){
        arr=new int [sentinel];
        for(int x=0;x<sentinel;x++){
            cout<<"Item "<<x+1<<" : ";
            cin>>value;
            *(arr+x)=value;
        }
    }else{exit(-1);}
}

int sortedAarry(int *arr,int sentinel,int index){
    
        int temp;

        for(int i=0; i<sentinel; i++)
        {
            for(int j=i+1; j<sentinel; j++)
            {
                //If there is a smaller element found on right of the array then swap it.
                if(arr[j] < arr[i])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

   return *(arr+index);
}

int main()
{
    int *array =NULL;
    int sen;
    
    cout<<endl<<endl;
    cout<<"How many items are you going to enter or (Enter -1 to terminate)?";
    cin>>sen;
    //The function below loads the values into the array
    arrValues(array,sen);
    
    int *longestSeq=NULL;
    int counter=1;

    for(int x=0;x<sen+1;x++){
        int difference=sen>1?( sortedAarry(array,sen,x+1)-sortedAarry(array,sen,x) ):sortedAarry(array,sen,0);
        if(difference==1){
            counter++;
        }
    } 
    
    longestSeq=new int[counter];

    for(int x=0;x<counter;x++){
        if(sortedAarry(array,sen,x+1)-sortedAarry(array,sen,x)!=0){
            *(longestSeq+x)=sortedAarry(array,sen,x);
        }
    }

    cout<<endl;
    cout<<"Longest Consecutive Sequence : "<<counter;
    cout<<endl<<endl<<endl;
    
	system("pause");
	return 0;
}