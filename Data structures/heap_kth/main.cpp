#include <bits/stdc++.h>
#include "priority_queue.h"
#include "student.h"
using namespace std;
int main() {
 int n = 10;
 CP::priority_queue<int> pq;
 while (n--) pq.push(n);
 cout << pq.get_kth(3) << endl; // แสดงค่า 7
 cout << pq.get_kth(2) << endl; // แสดงค่า 8
 cout << pq.get_kth(1) << endl; // แสดงค่า 9
 n = 10;
 CP::priority_queue<int,greater<int>> pq2;
 while (n--) pq2.push(n);
 cout << pq2.get_kth(3) << endl; // แสดงค่า 2
 cout << pq2.get_kth(2) << endl; // แสดงค่า 1
 cout << pq2.get_kth(1) << endl; // แสดงค่า 0
}