/*
 * macros.h
 *
 * Created: 9/5/2019 3:14:20 AM
 *  Author: Mostafa Tarek
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define REG_SIZE 8  

#define SET_BIT(REG,BIT)    REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)    REG&=(~(1<<BIT))
#define TOG_BIT(REG,BIT)    REG^=(1<<BIT)
#define READ_BIT(REG,BIT)   ((REG&(1<<BIT))>>BIT)
/* 
 IS_BIT_SET   =  READ_BIT   --> ONLY USED FOR READABILITY 
 IS_BIT_CLR   = !(READ_BIT) --> ONLY USED FOR READABILITY
*/
#define IS_BIT_SET(REG,BIT) ((REG&(1<<BIT))>>BIT)
#define IS_BIT_CLR(REG,BIT) !((REG&(1<<BIT))>>BIT)

#define ROT_left(REG,NUM)   REG = (REG<<NUM)|(REG>>(REG_SIZE-NUM))
#define ROT_RIGHT(REG,NUM)  REG = (REG>>NUM)|(REG<<(REG_SIZE-NUM))


#endif /* MACROS_H_ */