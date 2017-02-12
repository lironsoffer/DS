/*
 * functions.h
 *
 *  Created on: Feb 2, 2017
 *      Author: liron_s
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Node.h"
inline unsigned partition(Node** A, unsigned len, unsigned idx) //NOtice: CHanged
{
	if (idx!=0)
		swapNodes(A[idx],A[0]);
	unsigned b(1),t(len-1);
	while(b<=t)
	{
		while ((keyCmp(A[b],A[idx])))
		b++;
		while (keyCmp(A[idx],A[t]))
			t--;
		if (b<t)
		{
//			std::cout<<"swap "<<b<<" with "<<t<<std::endl;
			swapNodes(A[b],A[t]);
//			b++;
//			t--;
		}
	}
	return t;
}
inline unsigned quick_select(Node** v, unsigned n, unsigned k)
{
	    if (n == 1 && k == 0) return 0;

	    unsigned m = (n + 4)/5;
	    Node **medians = new Node*[m];
	    for (unsigned i=0; i<m; i++) {
	        if (5*i + 4 < n) {
	            Node **w = v + 5*i;
	            for (int j0=0; j0<3; j0++) {
	                int jmin = j0;
	                for (int j=j0+1; j<5; j++) {
	                    if (w[j]->key() < w[jmin]->key()) jmin = j;
	                }
	                swapNodes(w[j0], w[jmin]);
	            }
	            medians[i] = w[2];
	        } else {
	            medians[i] = v[5*i];
	        }
	    }

	    unsigned pivot = quick_select(medians, m, m/2);
	    delete [] medians;

	    for (unsigned i=0; i<n; i++) {
	        if (v[i] == v[pivot]) {
	            swapNodes(v[i], v[n-1]);
	            break;
	        }
	    }

	    unsigned store = 0;
	    for (unsigned i=0; i<n-1; i++) {
	        if (v[i] < v[pivot]) {
	            swapNodes(v[i], v[store++]);
	        }
	    }
	    swapNodes(v[store], v[n-1]);

	    if (store == k) {
	        return pivot;
	    } else if (store > k) {
	        return quick_select(v, store, k);
	    } else {
	        return quick_select(v+store+1, n-store-1, k-store-1);
	    }
}

#endif /* FUNCTIONS_H_ */
