#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    // same team => same league, 2
    // same league => check team
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    struct player{
        string name;
        string nation;
        string league;
        string team;
    };

    int n;
    player players[10];
    // int* connect_count = (int*)calloc(10, sizeof(int));
    int connect_count[10]={0,0,0,0,0,0,0,0,0,0};
    // vector<int> int_vector(10, 0);
    int synergy[10][10];
    int matrix[10][10];
    for(int i =0;i<10;i++){
        for(int j=0;j<10;j++){
            matrix[i][j]=0;
        }
    }
    int possible_places[10];

    cin>>n;
    for(int i = 0; i <n; i++){
        int a, b;
        cin >>a;
        cin >> b;
        
        matrix[a][b]=1;
        matrix[b][a]=1;

        connect_count[a]++;
        connect_count[b]++;
    }

    for (int i = 0; i<10;i++){
        possible_places[i] = i;
        cin>>players[i].name;
        cin>>players[i].nation;
        cin>>players[i].league;
        cin>>players[i].team;
    }
    for (int i = 0; i < 10; i++){
        for (int j= 0; j < 10; j++){
            if (i != j){
                synergy[i][j] = 0; // try
                if (!players[i].nation.compare(players[j].nation) && !players[i].team.compare(players[j].team)){
                    synergy[i][j] = 3;
                } else if (!players[i].nation.compare(players[j].nation) && !players[i].league.compare(players[j].league)){
                    synergy[i][j] = 2;
                } else if (!players[i].team.compare(players[j].team)){
                    synergy[i][j] = 2;
                }else if (!players[i].nation.compare(players[j].nation) || !players[i].league.compare(players[j].league)){
                    synergy[i][j] = 1;
                }
            }else{
                synergy[i][j] = 0;
            }
        }
    }
    bool found = true;
    do{
        found = true;
        int i = 0;
        int j = 0;
        for (i=0; i <10;i++){
            int total = 0;
            for (j=0; j < 10; j++){
                if (matrix[i][j]==1){
                    total += synergy[possible_places[i]][possible_places[j]];
                }
            }
            if (total < (connect_count[i])){
                found=false;
                break;
            }
        }
    } while (!found && next_permutation(possible_places, possible_places+10));
    if (found){
        cout<<"yes\n";
    } else{
        cout<<"no\n";
    }
    return 0;
}