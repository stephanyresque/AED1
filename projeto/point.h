
typedef struct ponto Ponto;

Ponto* pto_cria(float x, float y);

void pto_libera(Ponto *p);

int pto_acessa(Ponto *p, float* x,float* y);

int pto_atribui(Ponto* p,float x,float y);

float pto_distancia(Ponto* p1,Ponto* p2);
