#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n";
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pInt; 
const int mxn = 1000005; 

int front[mxn];
int back[mxn];
int n; long long ans, sum; 
int amtA[mxn]; int l[mxn]; 
int amtB[mxn]; int r[mxn];
set<int> eq;
set<int, greater<int>> e;

void ogMethod(){
    cout << ". "; 
    for (int i = 0; i < n; i++){
        cout << " " << front[i] << "  "; 
    }
    cout << ell 

    for (int i = 0; i < n; i++){
        cout << back[i] << " "; 
        for (int j = 0; j<n; j++){
            cout << "[" << min(front[j], back[i]) << "] "; 
            sum += min(front[j], back[i]); 
        }
       cout << endl << endl; 
    }
    cout << sum << endl; 
}

void shitMethod(){
    ll g = 0; 
    forl(n){
        cout << front[i] << "*" << i << " + " << back[i] << "*" << i << " + " << min(front[i], back[i]) << endl; 
        g += (front[i]*i) + (back[i]*i) + min(front[i], back[i]); 
    }
    cout << g << endl; 
}

int main(){
    inputJunk
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> front[i]; 
        eq.insert(front[i]); 
    }   
    for(int i = 1; i <= n; i++){
        cin >> back[i]; 
        if(eq.count(back[i])!=0){
            e.insert(back[i]); 
        }
    }
    cout << "SET MOMENT\n"; 
    int a = 0; int top; 
    for (auto elem : e){
        top = elem; 
        break; 
    }

    for (auto elem : e){
        cout << elem << ell
    }


    sort(front, front+n+1, greater<int>()); 
    sort(back, back+n+1, greater<int>()); 


    // DOES NOT ACCOUNT FOR INTERSECTION POINTS
    for(int i=0;i<n;i++){ 
        if (front[i] != front[i+1] or i==n-1){
            amtA[front[i+1]+1] += i+1;  
            amtA[front[i]+1] -= i+1;
            cout << "A: FROM " << front[i+1]+1 << " TO " << front[i]+1 << " VALUE IS " << i+1 << ell
        }
        if (back[i] != back[i+1] or i==n-1){
            amtB[back[i+1]+1] += i+1;  
            amtB[back[i]+1] -= i+1;
            cout << "B: FROM " << back[i+1]+1 << " TO " << back[i]+1 << " VALUE IS " << i+1 << ell
        }

    }


    for (int i = 1; i < mxn; i++){
        amtA[i] = amtA[i-1] + amtA[i]; 
        amtB[i] = amtB[i-1] + amtB[i]; 
    }
    for(int i = 1; i < n; i++){
        r[i] = r[front[i]] - r[front[i-1]];
        l[i] = l[back[i]]- l[back[i-1]];
    }
    cout << "\nR:"; 
    for(int i = 0; i <=100; i++){
        cout << r[i] << " "; 
    }

    cout << ell


    //REMOVING THE EXTRA UNACCOUNTED STUFF THAT WE DONT NEED
    ans -= amtA[top]*amtB[top]*top; 
    cout << "SUBTRACTING " << amtA[top]*amtB[top]*top << ell 
    int last = top; 
    for (auto i : e){
        if (i != top){
            int A = amtA[i]-amtA[last]; 
            int B = amtB[i]-amtB[last]; 
            if (A<=0){
                A = 1; 
            } 
            if (B<=0){
                B = 1; 
            }
            ans -= A*B*i;
            cout << i << " SUBTRACTING " << A << "*" << B << "*" <<  i << ell 
            last = i; 
        }
    }   


    cout << ell
    for(int i = 1; i <=top; i++){
        cout << i << " is less than or equal to " << amtA[i] << " items in list A" << ell
    }

    // The appearances for each row momento. 
    for(int i = 0; i < n; i++){
        int A = amtA[back[i]]; 
        int B = amtB[front[i]]; 
        if (A<=0){
            A = 1; 
        } 
        if (B<=0){
            B = 1; 
        }
        ans += (A * back[i] ) + (B*front[i]); 
        cout << front[i] << " makes " << amtB[front[i]] <<  " apperances\n"; 
    }
    cout << ell 
    for(int i = 0; i < n; i++){ 
        cout << back[i] << " makes " << amtA[back[i]] <<  " appearances\n"; 
    }

    ogMethod(); 

    cout << ans << endl; 

}

/* observations moment

The order of the rows and columns do not matter, their sum remains constant 

The two greatest numbers in each list are equal to each other



   8   7   7   7   3   3   3   2   2   2  
8 [8] [7] [7] [7] [3] [3] [3] [2] [2] [2] 

7 [7] [7] [7] [7] [3] [3] [3] [2] [2] [2] 

6 [6] [6] [6] [6] [3] [3] [3] [2] [2] [2] 

6 [6] [6] [6] [6] [3] [3] [3] [2] [2] [2] 

3 [3] [3] [3] [3] [3] [3] [3] [2] [2] [2] 

2 [2] [2] [2] [2] [2] [2] [2] [2] [2] [2] 

2 [2] [2] [2] [2] [2] [2] [2] [2] [2] [2] 

2 [2] [2] [2] [2] [2] [2] [2] [2] [2] [2] 

1 [1] [1] [1] [1] [1] [1] [1] [1] [1] [1] 

1 [1] [1] [1] [1] [1] [1] [1] [1] [1] [1]

the cock breaker ^


fix the count error when you are making that code run, everything works but the subtraction portion of it where the parts intersect. 


63082  shit code
61605  og code
64118 i am going to shit myself
63812 
*/