//
//  sorting_network.hpp
//  SORTING_NETWORK
//
//  Created by Galambos Mihály on 2017. 12. 09..
//  Copyright © 2017. Galambos Mihály. All rights reserved.
//

#ifndef sorting_network_h
#define sorting_network_h

#include "exceptions.hpp"
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
void blokk_rendezes(T *tomb, int meret, int kezd, int irany) {

    if(meret < 2) {
        return;
    }
    
    unsigned ismetles=0;
    unsigned ugras = meret/2;

    blokk_rendezes(tomb, meret/2, kezd, 1);
    blokk_rendezes(tomb, meret/2, kezd+meret/2,  2);
    
    for (unsigned lepes=ugras; lepes>0; lepes/=2) {
        for (unsigned i=0; i<pow(2, ismetles) && pow(2, ismetles) != meret; i++) {
            for (unsigned idx=0; idx<lepes; idx++) {
                
//                cout<<"Elotte:  [";
//                for(unsigned t=0; t<meret-1; t++) {
//                    cout<<tomb[t+kezd]<<", ";
//                }
//                cout<<tomb[meret+kezd-1]<<"]"<<endl;

                unsigned a = idx+kezd+i*lepes*2;
                unsigned b = idx+kezd+lepes+i*lepes*2;

                if(irany ==1) {
//                    cout<<"Ha teljesul csere: {"<<tomb[a]<<" > "<<tomb[b]<<"}"<<endl;
                    if(tomb[a] > tomb[b]) swap(tomb[a], tomb[b]);
                } else {
//                    cout<<"Ha teljesul csere: {"<<tomb[a]<<" < "<<tomb[b]<<"}"<<endl;
                    if(tomb[a] < tomb[b]) swap(tomb[a], tomb[b]);
                }
                
//                cout<<"Utana:  [";
//                for(unsigned t=0; t<meret-1; t++) {
//                    cout<<tomb[t+kezd]<<", ";
//                }
//                cout<<tomb[meret+kezd-1]<<"]"<<endl<<endl;
            }
        }
        ismetles++;
    }
}

template <typename T>
void rendezo_halozat(T *tomb, int meret) {
    if(meret % 2 != 0) throw invalid_size();
    
    blokk_rendezes(tomb, meret, 0, 1);
    
}

#endif /* sorting_network_h */
