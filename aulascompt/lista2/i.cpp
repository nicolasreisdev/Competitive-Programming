#include <bits/stdc++.h>
using namespace std;

struct eqps{
    string name;
    int pnts, games, win, tie, loss, goals, goalsc, goalsd;

};


int main(){
    int n, qtd, games; cin >> n;cin.ignore();
    for(int i = 0; i < n;i++){
        string name;
        getline(cin,name);
        cin >> qtd;
        cin.ignore();
        vector<eqps> times;
        for(int j = 0; j < qtd; j++){
            string x; getline(cin,x);
            times.push_back({x,0,0,0,0,0,0,0,0});
        }
        cin >> games;
        cin.ignore();
        vector<string> results;
        for(int j = 0; j < games; j++){
            string x; 
            getline(cin,x);
            results.push_back(x);
        }
        cout << name << endl;
        bool verifi;
        for(int j = 0; j < results.size();j++){
            verifi = false;
            int goals1, goals2, guard, guardeq1, guardeq2;
            for(int k = 0; k < results[j].size();k++){
                if (results[j][k] == '#' && verifi){
                    goals2 = stoi(results[j].substr(guard, k - guard));
                    string eqp2 = results[j].substr(k + 1, results[j].size() - k);
                    for (int l = 0; l < times.size(); l++){
                        if (times[l].name == eqp2){
                            times[l].games++;
                            times[l].goalsc += goals2;
                            guardeq2 = l;
                        }
                    }
                    if(goals1 > goals2){
                        times[guardeq1].goalsd += goals2;
                        times[guardeq2].goalsd += goals1;
                        times[guardeq1].pnts+=3;
                        times[guardeq1].win++;
                        times[guardeq2].loss++;
                    }
                    else if(goals1 < goals2){
                        times[guardeq2].goalsd += goals1;
                        times[guardeq1].goalsd += goals2;
                        times[guardeq2].pnts += 3;
                        times[guardeq2].win++;
                        times[guardeq1].loss++;
                    }
                    else{
                        times[guardeq1].goalsd += goals2;
                        times[guardeq2].goalsd += goals1;
                        times[guardeq1].pnts += 1;
                        times[guardeq2].pnts += 1;
                        times[guardeq1].tie++;
                        times[guardeq2].tie++;
                    }
                }
                if(results[j][k] == '#' && !verifi){
                    verifi = true;
                    guard = k+1;
                    string eqp1 = results[j].substr(0,k);
                    for(int l = 0; l < times.size();l++){
                        if(times[l].name == eqp1){
                            times[l].games++;
                            guardeq1 = l;
                        }
                    }
                }
                if(results[j][k] == '@'){
                    goals1 = stoi(results[j].substr(guard,k-guard));
                    times[guardeq1].goalsc += goals1;
                    guard = k+1;
                }
            }

        }
        for(int j = 0; j < times.size();j++){
            times[j].goals = times[j].goalsc - times[j].goalsd;
        }
        for(int j = 0; j < times.size();j++){
            for(int k = 0; k < times.size()-1;k++){
                if(times[k].pnts < times[k+1].pnts){
                    swap(times[k], times[k+1]);
                }
                else if (times[k].pnts == times[k + 1].pnts && times[k].win < times[k + 1].win){
                    swap(times[k], times[k + 1]);
                }
                else if (times[k].win == times[k + 1].win && times[k].goals < times[k+1].goals){
                    swap(times[k], times[k + 1]);
                }
                else if (times[k].goals == times[k + 1].goals && times[k].goalsc < times[k+1].goalsc){
                    swap(times[k], times[k + 1]);
                }
                else if (times[k].goalsc == times[k + 1].goalsc && times[k].games > times[k + 1].games){
                    swap(times[k], times[k + 1]);
                }
                else if (times[k].games == times[k + 1].games && times[k].name > times[k + 1].name){
                    for(int l = 0; l < times[k].name.size();l++){
                        if(times[k].name[l] > times[k+1].name[l]){
                            swap(times[k], times[k + 1]);
                            break;  
                        }
                        if(times[k].name[l]=='\0' && times[k+1].name[l]!='\0'){
                            swap(times[k], times[k + 1]);
                            break;
                        }
                    }
                }
            }
        }
        int acabaplmor = 1;
        for(int j = 0; j < times.size();j++){
            cout << acabaplmor << ") " << times[j].name << " " << times[j].pnts << "p, " << times[j].games << "g (" << 
            times[j].win << "-" << times[j].tie << "-" << times[j].loss << "), " << times[j].goals << "gd (" << 
            times[j].goalsc << "-" << times[j].goalsd << ")" << endl;   
            acabaplmor++; 
        }
        cout << endl;
    }


    return 0;
}