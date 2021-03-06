//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
struct TSel
{
TSel *next;
int num;
};
//---------------------------------------------------------------------------
TSel* AddStask(TSel *Sp, int S)
{
TSel *Spt;
Spt = (TSel *) malloc(sizeof(TSel));
Spt->num=S;
Spt->next=Sp;
return Spt;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Clear();
int n = StrToInt(Edit1->Text);
Edit1->Text = "";

TSel* Sp = NULL;
for(int i = 0; i < n; ++i)
Sp=AddStask(Sp, rand() % 100);

for(const TSel* i = Sp; i != NULL; i = i->next)
Memo1->Lines->Add(IntToStr(i->num));


// -----------[удаление 1 элемента]----------------

TSel* temp;
temp = Sp;
Sp = Sp->next;
delete temp;

// --------------[удаление последнего]-------------


TSel* first = Sp;
while(first->next->next != NULL){
        first = first->next;
}
first->next=NULL;





// --------------[Вывод результата]-------------
Memo1->Lines->Add("Результат");
for(const TSel* i = Sp; i != NULL; i = i->next)
Memo1->Lines->Add(IntToStr(i->num));


}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Clear();
Edit1->Text="";
}
//---------------------------------------------------------------------------

