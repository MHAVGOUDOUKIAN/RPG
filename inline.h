#ifndef INLINE_H_INCLUDED
#define INLINE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

inline int randomInt(int Min, int Max) // Renvoie un nombre entier dans l'intervalle [Min;Max]
{
    return (rand()%(1000*((Max+1)-Min)+1))/1000.+Min;
}

inline void erase_space(std::string &name_temp)
{
    for(long unsigned int i=0; i < name_temp.length() ; i++) {
        if(name_temp[i]=='_') {
            name_temp[i]=' ';
        }
    }
}

inline bool equal_string(std::string &ch1, std::string &ch2)
{
    bool est_egal = true;

    if(ch1.length() == ch2.length()) {
        for(long unsigned int i=0; i < ch1.length() ; i++) {
            if(ch1[i] != ch2[i]) {
                est_egal = false; 
            }
        }
    } 
    else
    {
        est_egal = false;
    }

    return est_egal;
}

inline float pwd(float src, const float n) // renvoie src^n
{
    if(n == 0) {
        return 1;
    }
    else if(n == 1)
    {
        return src;
    }
    
    src = src * pwd( src, n-1);
    return src;
}

#endif //INLINE_H_INCLUDED