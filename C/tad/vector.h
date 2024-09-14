
typedef struct floatvector FloatVector;

FloatVector* create(int capacity); //criar o vetor
int size(const FloatVector *vet);//retorna o tamanho
int capacity(const FloatVector *vet); //retorna a capacidade
float at(const FloatVector *vet,int index);//retorna uma pos do vetor
float get(const FloatVector *vet,int index);//retorna uma pos do vetor
void append(FloatVector *vet, float val); //incrementar
void set(FloatVector *vet,float val, int index); //alternar valor
void print(const FloatVector *vet); //printar vetor
void destroy(FloatVector **vec); //liberar memória