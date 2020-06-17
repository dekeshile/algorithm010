#define N 26

bool isAnagram(char * s, char * t){
   if(s == NULL || t == NULL)
    return false;
    int hash[N]={0};
    char* ps = s;
    while(*ps != '\0'){
        hash[*ps - 'a']++;
        ps++;
    }
    char* pt = t;
     while(*pt != '\0'){
        hash[*pt - 'a']--;
        pt++;
    }

    for(int i=0;i<N;i++){
        if(hash[i] != 0){
            return false;
        }
    }
    return true;
}