#ifdef DEBUG
#include<stdio.h>
#include<iostream>

using namespace std; 

template<class T>
struct heap {
	T* arr; 
	int sz;
	bool(*cmpFunc)(const T &a, const T &b); 
	heap(bool(*cmptype)(const T &a, const T &b)) {
		arr = new T[1001]; 
		sz = 0; 
		cmpFunc = cmptype; 
	}
	void push(T &a) {
		arr[++sz] = a; 
		upheap(); 
	}
	void upheap() {
		int cur = sz;
		while (cur / 2 >= 1 && cmpFunc(arr[cur], arr[cur / 2])) {
			SWAP(arr[cur], arr[cur / 2]);
			cur = cur / 2; 
		}
	}
	void pop() {
		arr[1] = arr[sz--]; 
		downheap(); 
	}
	void downheap() {
		int cur = 1; 
		while (cur * 2 <= sz) {
			int target = cur * 2; 
			if (target + 1 <= sz && cmpFunc(arr[target + 1], arr[target]))
				target++; 
			if (cmpFunc(arr[target], arr[cur])) {
				SWAP(arr[cur], arr[target]);
				cur = target;
			}
			else
				break; 
		}
	}
	T& top() {
		return arr[1]; 
	}
	int size() {
		return sz; 
	}
	int clear() {
		sz = 0; 
	}
	void SWAP(T &a, T &b) {
		T t = a; 
		a = b; 
		b = t; 
	}
};

template<class T>
bool minType(T &a, T &b) {
	return a < b; 
}

template<class T>
bool maxType(T &a, T &b) {
	return a > b; 
}

int main() {
	heap<int> s(maxType); int x; 
	for (int i = 0; i < 10; i++) {
		cin >> x; 
		s.push(x); 
	}
	int sz = s.size(); 
	for (int i = 0; i < sz; i++) {
		cout << s.top() << '\n'; 
		s.pop(); 
	}
	return 0; 
}
#endif // DEBUG
