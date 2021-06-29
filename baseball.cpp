#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand((unsigned int)time(0));

    // 1에서 9까지의 숫자 배열을 만든다.
    int iNumber[9];
    for(int i = 0; i < 9; ++i)
    {
        iNumber[i] = i + 1;
    }

    // suffle
    int iTemp, idx1, idx2;
    for(int i = 0; i < 100; ++i)
    {
        idx1 = rand()% 9;
        idx2 = rand()% 9;
    
    iTemp = iNumber[idx1];
    iNumber[idx1] = iNumber[idx2];
    iNumber[idx2] = iTemp;
    }

    // 일단 출력먼저 해보고 잘되면 ***로 출력 변경
    cout << iNumber[0] << iNumber[1] << iNumber[2] << endl;
    // 랜덤값이 정해졌으니 무한루프 안에서 문제풀이
    while (true)
    {
    int iStrike, iBall = 0;
    int iPlayer[3];


        cout << " 1부터 9까지의 숫자를 입력하세요." << endl;
        cin >> iPlayer[0] >> iPlayer[1] >> iPlayer[2];
        cout << endl;
        
        // 0이거나 숫자가 중복되면 게임이 안되게 함
        if(iPlayer[0]==0 || iPlayer[1]==0 || iPlayer[2]==0)
        {
            cout << "0을 입력할 수 없습니다" << endl;
            break;
        }
        else if(iPlayer[0]==iPlayer[1] || iPlayer[0]==iPlayer[2]
                || iPlayer[1]==iPlayer[2])
        {
            cout << " 중복된 숫자를 입력할 수 없습니다 " << endl;
            continue;
        }
        else if(iPlayer[0]<0 || iPlayer[0] > 9 || iPlayer[1]<0 || iPlayer[1] > 9 || 
                iPlayer[2]<0 || iPlayer[2] > 9)
        {
            cout << "0보다 작거나 9보다 큰 수를 입력할 수 없습니다";
            continue;
        }

        iStrike = iBall = 0;

        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j)
            {
                if(iPlayer[i]==iNumber[j]){
                    if(i==j)
                    {
                        ++iStrike;
                    }
                    else
                    {
                        ++iBall;
                    }
                }
            }
        }

        if(iStrike==0 && iBall ==0)
        {
            cout << " Out " << endl;
        }
        else if(iStrike == 3)
        {
            cout << " 모든 숫자를 맞췄습니다" << endl;
            break;
        }
        else
        {
            cout << iStrike << " strike " << iBall << " Ball " << endl;
        }
    }

}