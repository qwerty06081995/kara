# kara
Kara 3d Game engine

if you have complier error like:undeclared identifier error,the 'DC' is undeclared ,then you need to change the 'imgui.cpp' file , find the line 3839 and 3841,change it to "for (int i = 0; i < window->DC.Layouts.Data.Size; i++)"  and "ImGuiLayout* layout = (ImGuiLayout*)window->DC.Layouts.Data[i].val_p;"
