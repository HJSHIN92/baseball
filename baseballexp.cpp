#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand((unsigned int)time(0));
    
    int iNumber[9] = {};
    for(int i = 0 ; i < 9; ++i)
    {
        iNumber[i] = i + 1;
    }

    int iTemp, idx1, idx2;
    for(int i = 0; i < 100; ++i)
    {
        idx1 = rand()%9;
        idx2 = rand()%9;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }

    for(int i = 0; i < 3; ++i)
    {
        cout << iNumber[i] << "\t" ;
    }
    cout << endl;

    while (true)
    {
        cout << "1 ~ 9 사이의 숫자 세개를 골라주세요 (종료 : 0)" << endl;
        int iInput[3];
        cin >> iInput[0] >> iInput[1] >> iInput[2];

        if(iInput[0]==0 || iInput[1]==0 || iInput[2]==0)
        {
            cout << "종료합니다 " << endl;
            break;
        }

        else if(iInput[0]<0 || iInput[0]>9 || iInput[1]<0 || iInput[1]>9 ||
            iInput[2]<0 || iInput[2]>9)
        {
            cout << " 0 - 9 사이의 숫자를 입력하세요. "<< endl;
            continue;
        }

        int iStrike, iBall;
        iStrike = iBall = 0;
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(iInput[i]==iNumber[j])
                {
                    if(i==j)
                        ++iStrike;
                    else
                        ++iBall;
                }
            }
        }

        if(iStrike ==0 && iBall == 0)
            cout << "Out" << endl;
        else if(iStrike == 3)
            cout << "모두 맞췄습니다 축하드려요" << endl;
        else
            cout << iStrike <<" 스트라이크 " << iBall << "볼" << endl;
    }   
    
}
    
