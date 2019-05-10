#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>

using namespace std;

int i;
string msg;
string key, subkey1="", subkey2="", buffer="", enh1="", enh2="";
string hashsum;
unsigned int cryptedhash;
unsigned int keymatrix[32]={1,15,9,2,21,8,19,27,2,6,24,18,3,20,14,25,4,11,5,13,23,4,26,17,8,28,12,10,1,22,16,7};
unsigned int trans[32]={5,16,22,9,28,6,19,29,30,13,3,20,14,31,8,24,2,26,17,10,15,4,21,7,32,12,11,23,1,25,18,27};
static char bin[CHAR_BIT + 1] = { 0 };
static char h[CHAR_BIT + 1] = { 0 };
char* binary ( unsigned char c )
{

    for ( i = CHAR_BIT - 1; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }
    return bin;
}

void hashing()
{
    h[0]=bin[0]^bin[2]^bin[4];
    h[1]=bin[1]^bin[5]^bin[7];
    h[2]=bin[3]^bin[5]^bin[6];
    h[3]=bin[1]^bin[3]^bin[7];
    h[4]=bin[2]^bin[4]^bin[6];
    h[5]=bin[0]^bin[2]^bin[4];
    h[6]=bin[2]^bin[5]^bin[6];
    h[7]=bin[0]^bin[4]^bin[7];
}

void keygen()
{
    srand(time(0));
     for(int c=0;c<28;c++)
     {
         subkey1+=to_string(rand()%2);
     }
     for(int c=28;c<56;c++)
     {
         subkey2+=to_string(rand()%2);
     }
     key=subkey1+subkey2;
    cout<<"Generated key: "<<key<<endl;
};

void keyto64()
{
for(int z=0;z<32;z++)
{
    enh1+=subkey1[keymatrix[z]];
    enh2+=subkey2[keymatrix[z]];
};
    enh1+=enh2;
cout<<"Enhanced key : "<<enh1<<endl;
}

void crypt()
{int r=0;
    if(hashsum.length()%64!=0)
    {
        hashsum+='1';
        while(hashsum.length()%64!=0)
        {
            hashsum+='0';
        }
    };
    cout<<endl<<"Current sum: "<<hashsum<<endl;
    for(int z=0;z<hashsum.length();z++)
    {
    buffer+=hashsum[trans[r]];
    r++;
    if(r==32)r=0;
    }
    cout<<endl<<"Total block state after all transforms: \n"<<buffer<<endl;
    unsigned int toi1, toi2;
    toi1 = atoi(buffer.c_str());
    toi2 = atoi(enh1.c_str());
    cryptedhash=toi1^toi2;
}

int main()
{
    cout<<"Enter message to encrypt: ";
 cin>>msg;

 cout<<"All right, now let's decompile this message and watch it's binary codes";
 cout<<"\n Wait a moment... It is not so easy..."<<endl;
 cout<<"symbol"<<"\t"<<"binary"<<"\t\t"<<"hashing \n";
 for(int j=0;j<msg.length();j++)
  {
   binary(msg[j]);
   hashing();
   hashsum+=h;
   cout<<msg[j]<<"\t"<<bin<<"\t"<<h<<"\n";
  };

 cout<<"Total hashsum with no encryption \n"<<hashsum<<endl;
 cout<<"Now, let me generate once-usable bit-key...\n"<<endl;
 keygen();
 cout<<"Now, let's enhance it a bit more... 56 to 64 bits would be enough\n"<<endl;
 keyto64();
 cout<<"And now I'll encrypt this hash and recompile it in decimal code\n"<<endl;
 crypt();
 cout<<endl;
 cout<<"My result of encryption: ";
 cout<<cryptedhash<<endl;
 cout<<"That's all!"<<endl;
 cin.get();
 return 0;
}
