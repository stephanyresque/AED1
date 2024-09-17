typedef struct complexo Complexo;

Complexo* create(float x, float y);
void destroy(Complexo **num);
float soma_complexo(Complexo *num1, Complexo *num2);
float subtrai_complexo(Complexo *num1, Complexo *num2);
float multiplica_complexo(Complexo *num1, Complexo *num2);
