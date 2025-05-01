#include <iostream>
using namespace std;

int tilingproblem(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans1 = tilingproblem(n-1);// vertical
    int ans2  = tilingproblem(n-2);

    return ans1 + ans2;
}

int main(){
    int n = 3;
    cout << tilingproblem(n) << endl;
    return 0;
}

/*
tilingproblem(3)
├── tilingproblem(2)   ← place one vertical tile
│   ├── tilingproblem(1)   ← place one vertical tile again
│   │   └── returns 1      ← base case (n == 1)
│   └── tilingproblem(0)   ← place two horizontal tiles
│       └── returns 1      ← base case (n == 0)
│   └── returns 1 + 1 = 2
│
└── tilingproblem(1)   ← place two horizontal tiles
    └── returns 1      ← base case (n == 1)

Final result = 2 (from tilingproblem(2)) + 1 (from tilingproblem(1)) = **3**

🧠 What’s happening at each step?
From n = 3, it tries placing:

One tile vertically → then solves for n = 2

Two tiles horizontally → then solves for n = 1

From n = 2, it again tries both options:

Vertical → solve for n = 1

Horizontal → solve for n = 0

These branches continue until they hit the base cases (n == 0 or n == 1) and return 1.

✅ All Valid Combinations (Visual Intuition):
V V V — three vertical tiles

H H + V — two horizontals (covering 2 columns) then one vertical

V + H H — one vertical first, then two horizontals

So, 3 ways in total — and recursion explores each path step by step.*/