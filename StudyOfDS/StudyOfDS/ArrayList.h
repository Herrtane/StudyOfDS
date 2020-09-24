#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 1000

/** 
* @brief	array를 이용한 sorted list
* @detail	어떤 datatype이든지 사용할 수 있도록 template을 이용해서 generic하게 구현
* @date		2020-09-21
* @author	herrtane@gmail.com
* @version	생략
*/

template <class T>
class ArrayList
{
private:
	int m_length;			// m_array안의 원소수
	int m_currentPos;		// m_array에서 현재 가리키는 위치
	T* m_array;				// m_array를 가리키는 포인터

public:
	ArrayList();
	~ArrayList();

	/**
	* @brief	m_length를 반환해주는 함수
	* @date		2020-09-21
	* @return	m_length
	* @param	없음
	*/
	int GetLength();
	/**
	* @brief	m_array가 가득 찼는지 여부를 알려주는 함수
	* @date		지금부터는 생략
	* @return	true or false
	* @param	없음
	*/
	bool IsFull();
	/**
	* @brief	m_array가 비어있는지 여부를 알려주는 함수
	* @date		지금부터는 생략
	* @return	true or false
	* @param	없음
	*/
	bool IsEmpty();
	/**
	* @brief	m_array를 빈 배열로 만듦
	* @date		생략
	* @return	없음
	* @param	없음
	*/
	void MakeEmpty();

	/**
	* @brief	배열에 원소 하나를 id순서에 맞게 추가 
	* @detail	해당 itemtype의 operator overloading 구현 필요, Binary Search로 구현 못함
	* @date		생략
	* @return	성공시 1, 실패시 0 반환
	* @param	새로 들어갈 T item
	*/
	int InsertItem(T item);
	/**
	* @brief	배열에서 원소 하나를 삭제
	* @detail	Binary Search로 구현 못함
	* @date		생략
	* @return	성공시 1, 실패시 0 반환
	* @param	삭제할 T item
	*/
	int DeleteItem(T item);
	/**
	* @brief	인자로 받은 item의 id와 일치하는 배열의 원소를 찾아줌
	* @detail	by Binary Search
	* @date		생략
	* @return	성공시 1, 실패시 0 반환
	* @param	찾고싶은 T item
	*/
	int RetrieveItem(T& item);

	/**
	* @brief	m_currentPos를 -1로 초기화
	* @date		생략
	* @return	없음
	* @param	없음
	*/
	void ResetList();
	/**
	* @brief	m_currentPos의 다음 원소를 반환해줌
	* @date		생략
	* @return	
	* @param	반환받을 대상인 T item
	*/
	int GetNextItem(T& item);
};

template <class T>
ArrayList<T>::ArrayList() {
	m_length = 0;
	m_currentPos = -1;
	m_array = new T[MAXSIZE];
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete[] m_array;
}

template <class T>
int ArrayList<T>::GetLength() {
	return m_length;
}

template <class T>
bool ArrayList<T>::IsFull() {
	if (m_length == MAXSIZE)
		return true;
	else
		return false;
}

template <class T>
bool ArrayList<T>::IsEmpty() {
	if (m_length <= 0)
		return true;
	else
		return false;
}

template <class T>
void ArrayList<T>::MakeEmpty() {
	m_length = 0;
}

template <class T>
int ArrayList<T>::InsertItem(T item) {
	if (!IsFull()) {

		int location = 0;

		while (location < m_length) {				// 만약 insert할 위치가 맨끝이라면 while루프 조건때문에 다음으로 넘어갈 것이고
													// 만약 insert할 위치가 중간이라면 item<m_array[location]이 되면 break되어 다음으로 넘어갈 것이고
													// 만약 insert할 위치에 이미 다른 원소가 있다면 0을 반환하면서 중단될 것이다.
			if (item < m_array[location])
				break;
			else if (item > m_array[location])
				location++;
			else
				return 0;
		}

		for (int i = m_length; i > location; i--)
			m_array[i] = m_array[i - 1];

		m_array[location] = item;
		m_length++;
		return 1;
	}

	return 0;
}

template <class T>
int ArrayList<T>::DeleteItem(T item) {
	int location;
	bool found = false;

	for (location = 0; location < m_length; location++) {
		if (item == m_array[location]) {
			found = true;
			break;
		}
	}

	if (!found)
		return 0;

	for (int i = location + 1; i < m_length; i++)
		m_array[i - 1] = m_array[i];
	m_length--;
	return 1;
}

template <class T>
int ArrayList<T>::RetrieveItem(T& item) {
	int midPoint;
	int first = 0;
	int last = m_length - 1;
	bool found = false;

	while ((first <= last) && !found) {

		midPoint = (first + last) / 2;

		if (item < m_array[midPoint])
			last = midPoint - 1;
		else if (item > m_array[midPoint])
			first = midPoint + 1;
		else {
			found = true;
			item = m_array[midPoint];
			return 1;
		}
	}
	return 0;
}

template <class T>
void ArrayList<T>::ResetList() {
	m_currentPos = -1;
}

template <class T>
int ArrayList<T>::GetNextItem(T& item) {
	m_currentPos++;
	if (m_currentPos == m_length)
		return 0;
	item = m_array[m_currentPos];
	return 1;
}