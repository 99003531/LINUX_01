#ifndef __SENDSIGNAL_H
#define __SENDSIGNAL_H

#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
void childprocess();
void sighup(); 
void sigint(); 
void sigquit(); 

#endif
