#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    std::cin >> n;
    while(n--){
        deque<int> deck;
        int N;
        std::cin >> N;
        for(int i = N; i > 0; i--){
            deck.push_front(i);
            for(int j = 0; j < i; j++){
                int last_card = deck.back();
                deck.pop_back();
                deck.push_front(last_card);
            }
        }
        for(auto elem : deck){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
