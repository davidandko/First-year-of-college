/*
 * main.cpp
 *
 *  Created on: Apr 8, 2022
 *      Author: David
 *
*/
#include<iostream>

using namespace std;
// edinecno povrzana
/*
int list_length(node *head){ // dolzina na lista
	int n = 0;
	while (head != NULL){
		head = head->link;
		n++;
	}
	return n;
}

node *find_first(node *head, int data){ // naogjanje na daden jazol so info pole
	node *dvizi = head;
	while (dvizi != NULL && dvizi->info != data)
	{
		dvizi = dvizi->link;
	}
	return dvizi;
}
void insert_inside(node *jazol, int data) // nov jazol posle daden jazol
{
	node *tmp = new node;
	tmp->info = data;
	tmp->link = jazol->link;
	jazol->link = tmp;
}
void delete_after(node *jazol){	// Brisenje na jazol posle daden jazol
	if (jazol->link == NULL)
		return;

	node *tmp = jazol->link; //tmp е следбеник
	jazol->link = tmp->link;
	delete tmp;
}

int delete_node(node *head, node *jazol){ // brisenje na daden jazol
	if (head == jazol)
		head = jazol->link;
	else
	{
		node *pom = *head;
		while (pom->link != jazol && pom != NULL){
			pom = pom->link;
		}
		if (pom == NULL){
			return 0; //не сме го нашле
		}
		pom->link = jazol->link;
	}
	delete jazol;
	return 1;
}
void insert_front(node jazol, int data){ // vmetnuvanje na daden jazol na pozicija head
	if(head==NULL){
		jazol->link = NULL;
		head = jazol;
		return;
	}
	jazol->link = head;
	head = jazol;
}
*/


// dvojno povrzani

void ins_before(nodep l, info_t x){ // sozdavanje na nov jazol pred daden jazol

	nodep t = new node;
	t->info = x;
	l->prev->next = t;
	t->prev = l->prev;
	t->next = l;
	l->prev = t;
}

void deleteJazol(Jazol *node){ // brisenje na daden jazol
		if(node == head){
			deleteFirst();
		}
		else{
			Jazol *prethodnik = node->prev;
			Jazol *sledbenik = node->next;
			prethodnik->next = sledbenik;
			sledbenik->prev = prethodnik;
			delete node;
		}

	}

