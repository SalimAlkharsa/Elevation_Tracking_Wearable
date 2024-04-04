#include <string.h>
#include <math.h>

void softmax(double *x, int size, double *result)
{
    double max = x[0];
    for (int i = 1; i < size; ++i)
    {
        if (x[i] > max)
            max = x[i];
    }
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
    {
        result[i] = exp(x[i] - max);
        sum += result[i];
    }
    for (int i = 0; i < size; ++i)
        result[i] /= sum;
}
void score(double *input, double *output)
{
    double var0[5];
    double var1;
    if (input[49] >= 96206.59)
    {
        var1 = -0.06227106;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 232.2939)
            {
                var1 = 0.053281154;
            }
            else
            {
                var1 = 0.12822102;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var1 = -0.01091703;
            }
            else
            {
                var1 = -0.061731428;
            }
        }
    }
    double var2;
    if (input[49] >= 96206.59)
    {
        var2 = -0.061270148;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 232.2939)
            {
                var2 = 0.048130702;
            }
            else
            {
                var2 = 0.109655194;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var2 = -0.010045079;
            }
            else
            {
                var2 = -0.060682174;
            }
        }
    }
    double var3;
    if (input[49] >= 96206.59)
    {
        var3 = -0.06035723;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 351.15268)
            {
                var3 = 0.042803228;
            }
            else
            {
                var3 = 0.094554044;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var3 = -0.0089813825;
            }
            else
            {
                var3 = -0.059803654;
            }
        }
    }
    double var4;
    if (input[49] >= 96206.59)
    {
        var4 = -0.059503924;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 232.2939)
            {
                var4 = 0.040020075;
            }
            else
            {
                var4 = 0.084382005;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var4 = -0.008094574;
            }
            else
            {
                var4 = -0.058952283;
            }
        }
    }
    double var5;
    if (input[49] >= 96206.59)
    {
        var5 = -0.05871522;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var5 = -0.007200112;
            }
            else
            {
                var5 = -0.058389246;
            }
        }
        else
        {
            if (input[28] >= 356.90076)
            {
                var5 = 0.035749737;
            }
            else
            {
                var5 = 0.07448887;
            }
        }
    }
    double var6;
    if (input[49] >= 96206.59)
    {
        var6 = -0.057980366;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 356.90076)
            {
                var6 = 0.032687154;
            }
            else
            {
                var6 = 0.06753152;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var6 = -0.0061956877;
            }
            else
            {
                var6 = -0.057557076;
            }
        }
    }
    double var7;
    if (input[49] >= 96206.59)
    {
        var7 = -0.057312835;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var7 = -0.0052671744;
            }
            else
            {
                var7 = -0.057128634;
            }
        }
        else
        {
            if (input[7] >= 1.3818359)
            {
                var7 = 0.040462237;
            }
            else
            {
                var7 = 0.089138016;
            }
        }
    }
    double var8;
    if (input[49] >= 96206.59)
    {
        var8 = -0.056690153;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 232.2939)
            {
                var8 = 0.027291123;
            }
            else
            {
                var8 = 0.058186453;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var8 = -0.004238281;
            }
            else
            {
                var8 = -0.056355674;
            }
        }
    }
    double var9;
    if (input[49] >= 96206.59)
    {
        var9 = -0.056125876;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var9 = -0.0032871116;
            }
            else
            {
                var9 = -0.056054752;
            }
        }
        else
        {
            if (input[7] >= 3.05542)
            {
                var9 = 0.09436029;
            }
            else
            {
                var9 = 0.03535993;
            }
        }
    }
    double var10;
    if (input[49] >= 96206.59)
    {
        var10 = -0.055596877;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 351.15268)
            {
                var10 = 0.021852827;
            }
            else
            {
                var10 = 0.04992228;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var10 = -0.0022943842;
            }
            else
            {
                var10 = -0.055351477;
            }
        }
    }
    double var11;
    if (input[49] >= 96206.59)
    {
        var11 = -0.05512006;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var11 = -0.000866763;
            }
            else
            {
                var11 = -0.055166032;
            }
        }
        else
        {
            if (input[7] >= 1.3056641)
            {
                var11 = 0.029321963;
            }
            else
            {
                var11 = 0.074372366;
            }
        }
    }
    double var12;
    if (input[49] >= 96206.59)
    {
        var12 = -0.054674815;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var12 = 0.0005218803;
            }
            else
            {
                var12 = -0.054705855;
            }
        }
        else
        {
            if (input[7] >= 3.05542)
            {
                var12 = 0.07673465;
            }
            else
            {
                var12 = 0.027758956;
            }
        }
    }
    double var13;
    if (input[49] >= 96206.59)
    {
        var13 = -0.054267164;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 232.2939)
            {
                var13 = 0.016709922;
            }
            else
            {
                var13 = 0.041544612;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var13 = 0.0014165732;
            }
            else
            {
                var13 = -0.054104824;
            }
        }
    }
    double var14;
    if (input[49] >= 96206.59)
    {
        var14 = -0.0538893;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var14 = 0.0026280219;
            }
            else
            {
                var14 = -0.053982127;
            }
        }
        else
        {
            if (input[7] >= 1.3818359)
            {
                var14 = 0.022546528;
            }
            else
            {
                var14 = 0.057336908;
            }
        }
    }
    double var15;
    if (input[49] >= 96206.59)
    {
        var15 = -0.05353821;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[7] >= 3.05542)
            {
                var15 = 0.06545004;
            }
            else
            {
                var15 = 0.02223733;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var15 = 0.0034379219;
            }
            else
            {
                var15 = -0.05340591;
            }
        }
    }
    double var16;
    if (input[49] >= 96206.59)
    {
        var16 = -0.053215653;
    }
    else
    {
        if (input[42] >= 27.825)
        {
            if (input[42] >= 28.485)
            {
                var16 = 0.004257209;
            }
            else
            {
                var16 = -0.05334243;
            }
        }
        else
        {
            if (input[7] >= 1.3818359)
            {
                var16 = 0.01946023;
            }
            else
            {
                var16 = 0.051795777;
            }
        }
    }
    double var17;
    if (input[49] >= 96206.59)
    {
        var17 = -0.05291101;
    }
    else
    {
        if (input[49] >= 94912.766)
        {
            if (input[28] >= 356.90076)
            {
                var17 = 0.010790776;
            }
            else
            {
                var17 = 0.03350277;
            }
        }
        else
        {
            if (input[42] >= 27.335)
            {
                var17 = -0.02940627;
            }
            else
            {
                var17 = 0.057694227;
            }
        }
    }
    double var18;
    if (input[49] >= 96206.59)
    {
        var18 = -0.052618027;
    }
    else
    {
        if (input[49] >= 94912.766)
        {
            if (input[7] >= 3.05542)
            {
                var18 = 0.06123001;
            }
            else
            {
                var18 = 0.018159011;
            }
        }
        else
        {
            if (input[56] >= 96.5)
            {
                var18 = 0.0061540636;
            }
            else
            {
                var18 = -0.051150948;
            }
        }
    }
    double var19;
    if (input[49] >= 96206.59)
    {
        var19 = -0.052349616;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 24.965)
            {
                var19 = 0.067972116;
            }
            else
            {
                var19 = -0.0095154075;
            }
        }
        else
        {
            if (input[56] >= 115.5)
            {
                var19 = 0.022545671;
            }
            else
            {
                var19 = -0.006072805;
            }
        }
    }
    double var20;
    if (input[49] >= 96206.59)
    {
        var20 = -0.052091148;
    }
    else
    {
        if (input[49] >= 94869.61)
        {
            if (input[28] >= 232.2939)
            {
                var20 = 0.008597196;
            }
            else
            {
                var20 = 0.02861459;
            }
        }
        else
        {
            if (input[42] >= 28.485)
            {
                var20 = 0.009536576;
            }
            else
            {
                var20 = -0.052393515;
            }
        }
    }
    double var21;
    if (input[49] >= 96206.59)
    {
        var21 = -0.051853694;
    }
    else
    {
        if (input[7] >= 2.5336914)
        {
            if (input[21] >= 99.70993)
            {
                var21 = 0.016179834;
            }
            else
            {
                var21 = 0.048891887;
            }
        }
        else
        {
            if (input[7] >= 1.3879395)
            {
                var21 = 0.005170093;
            }
            else
            {
                var21 = 0.038177695;
            }
        }
    }
    double var22;
    if (input[49] >= 96206.59)
    {
        var22 = -0.05162522;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 24.974998)
            {
                var22 = 0.06418072;
            }
            else
            {
                var22 = -0.002500983;
            }
        }
        else
        {
            if (input[56] >= 115.5)
            {
                var22 = 0.01909491;
            }
            else
            {
                var22 = -0.006515935;
            }
        }
    }
    double var23;
    if (input[49] >= 96206.59)
    {
        var23 = -0.0514072;
    }
    else
    {
        if (input[7] >= 2.5336914)
        {
            if (input[21] >= 99.70993)
            {
                var23 = 0.013942982;
            }
            else
            {
                var23 = 0.044957988;
            }
        }
        else
        {
            if (input[7] >= 1.3879395)
            {
                var23 = 0.004209207;
            }
            else
            {
                var23 = 0.035160165;
            }
        }
    }
    double var24;
    if (input[49] >= 96206.59)
    {
        var24 = -0.051197436;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 24.974998)
            {
                var24 = 0.058897216;
            }
            else
            {
                var24 = -0.0024327298;
            }
        }
        else
        {
            if (input[56] >= 115.5)
            {
                var24 = 0.017105877;
            }
            else
            {
                var24 = -0.006446004;
            }
        }
    }
    double var25;
    if (input[49] >= 96206.59)
    {
        var25 = -0.05098904;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 24.974998)
            {
                var25 = 0.054782104;
            }
            else
            {
                var25 = -0.0016679969;
            }
        }
        else
        {
            if (input[56] >= 115.5)
            {
                var25 = 0.016030157;
            }
            else
            {
                var25 = -0.0057838606;
            }
        }
    }
    double var26;
    if (input[49] >= 96206.59)
    {
        var26 = -0.050796594;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[28] >= 232.2939)
            {
                var26 = 0.0032919273;
            }
            else
            {
                var26 = 0.024525158;
            }
        }
        else
        {
            if (input[7] >= 1.6367188)
            {
                var26 = -0.04216251;
            }
            else
            {
                var26 = 0.018293485;
            }
        }
    }
    double var27;
    if (input[49] >= 96206.59)
    {
        var27 = -0.05060175;
    }
    else
    {
        if (input[7] >= 2.5336914)
        {
            if (input[0] >= 0.52612305)
            {
                var27 = 0.020482434;
            }
            else
            {
                var27 = 0.05260932;
            }
        }
        else
        {
            if (input[7] >= 1.3879395)
            {
                var27 = 0.002477866;
            }
            else
            {
                var27 = 0.030687345;
            }
        }
    }
    double var28;
    if (input[49] >= 96206.59)
    {
        var28 = -0.050414015;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 25.145)
            {
                var28 = 0.054661453;
            }
            else
            {
                var28 = 0.0029484592;
            }
        }
        else
        {
            if (input[56] >= 115.5)
            {
                var28 = 0.013786125;
            }
            else
            {
                var28 = -0.0062973197;
            }
        }
    }
    double var29;
    if (input[49] >= 96206.59)
    {
        var29 = -0.050211933;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[28] >= 232.2939)
            {
                var29 = 0.0024677545;
            }
            else
            {
                var29 = 0.021643322;
            }
        }
        else
        {
            if (input[7] >= 1.6367188)
            {
                var29 = -0.041907754;
            }
            else
            {
                var29 = 0.015850505;
            }
        }
    }
    double var30;
    if (input[49] >= 96206.59)
    {
        var30 = -0.050030798;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[49] >= 96088.484)
            {
                var30 = 0.034144334;
            }
            else
            {
                var30 = 0.00761665;
            }
        }
        else
        {
            if (input[7] >= 1.6367188)
            {
                var30 = -0.040504273;
            }
            else
            {
                var30 = 0.014811925;
            }
        }
    }
    double var31;
    if (input[49] >= 96206.59)
    {
        var31 = -0.04984278;
    }
    else
    {
        if (input[7] >= 2.5336914)
        {
            if (input[21] >= 99.70993)
            {
                var31 = 0.0066281366;
            }
            else
            {
                var31 = 0.035855286;
            }
        }
        else
        {
            if (input[7] >= 1.3879395)
            {
                var31 = 0.0013115202;
            }
            else
            {
                var31 = 0.026319683;
            }
        }
    }
    double var32;
    if (input[49] >= 96206.59)
    {
        var32 = -0.04965466;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[28] >= 232.2939)
            {
                var32 = 0.0018068961;
            }
            else
            {
                var32 = 0.019084139;
            }
        }
        else
        {
            if (input[14] >= 4.5214844)
            {
                var32 = -0.0026171163;
            }
            else
            {
                var32 = -0.050182868;
            }
        }
    }
    double var33;
    if (input[49] >= 96206.59)
    {
        var33 = -0.04945684;
    }
    else
    {
        if (input[7] >= 2.5336914)
        {
            if (input[21] >= 99.70993)
            {
                var33 = 0.00570567;
            }
            else
            {
                var33 = 0.03356008;
            }
        }
        else
        {
            if (input[28] >= 315.73663)
            {
                var33 = -0.004201522;
            }
            else
            {
                var33 = 0.0129489;
            }
        }
    }
    double var34;
    if (input[49] >= 96206.59)
    {
        var34 = -0.049271937;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 25.145)
            {
                var34 = 0.048162784;
            }
            else
            {
                var34 = -0.0013312444;
            }
        }
        else
        {
            if (input[42] >= 25.475)
            {
                var34 = 0.008795748;
            }
            else
            {
                var34 = -0.014065099;
            }
        }
    }
    double var35;
    if (input[49] >= 96206.59)
    {
        var35 = -0.049080472;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[28] >= 232.2939)
            {
                var35 = 0.0013769505;
            }
            else
            {
                var35 = 0.016824922;
            }
        }
        else
        {
            if (input[7] >= 1.6367188)
            {
                var35 = -0.038920235;
            }
            else
            {
                var35 = 0.014017153;
            }
        }
    }
    double var36;
    if (input[49] >= 96206.59)
    {
        var36 = -0.04888139;
    }
    else
    {
        if (input[49] >= 96088.484)
        {
            if (input[42] >= 25.145)
            {
                var36 = 0.04477536;
            }
            else
            {
                var36 = -0.00048946723;
            }
        }
        else
        {
            if (input[14] >= 7.805908)
            {
                var36 = 0.019033322;
            }
            else
            {
                var36 = -0.00049877854;
            }
        }
    }
    double var37;
    if (input[56] >= 92.5)
    {
        if (input[49] >= 95656.75)
        {
            if (input[7] >= 3.0480957)
            {
                var37 = 0.0426182;
            }
            else
            {
                var37 = 0.0010645048;
            }
        }
        else
        {
            if (input[42] >= 27.455)
            {
                var37 = 0.0052993507;
            }
            else
            {
                var37 = 0.047054455;
            }
        }
    }
    else
    {
        if (input[42] >= 27.485)
        {
            if (input[21] >= 498.03436)
            {
                var37 = -0.028657055;
            }
            else
            {
                var37 = -0.05943206;
            }
        }
        else
        {
            if (input[28] >= 76.63359)
            {
                var37 = 0.014570101;
            }
            else
            {
                var37 = -0.02610783;
            }
        }
    }
    double var38;
    if (input[56] >= 92.5)
    {
        if (input[49] >= 95656.75)
        {
            if (input[42] >= 26.36)
            {
                var38 = -0.009183296;
            }
            else
            {
                var38 = 0.0121771805;
            }
        }
        else
        {
            if (input[42] >= 27.455)
            {
                var38 = 0.005117137;
            }
            else
            {
                var38 = 0.043809466;
            }
        }
    }
    else
    {
        if (input[42] >= 27.485)
        {
            if (input[21] >= 498.03436)
            {
                var38 = -0.027791742;
            }
            else
            {
                var38 = -0.05909285;
            }
        }
        else
        {
            if (input[28] >= 76.63359)
            {
                var38 = 0.013544328;
            }
            else
            {
                var38 = -0.02501725;
            }
        }
    }
    double var39;
    if (input[49] >= 96206.59)
    {
        var39 = -0.048382428;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[28] >= 232.2939)
            {
                var39 = 0.00048401818;
            }
            else
            {
                var39 = 0.015074168;
            }
        }
        else
        {
            if (input[35] >= 485.87787)
            {
                var39 = 0.01346124;
            }
            else
            {
                var39 = -0.037779182;
            }
        }
    }
    double var40;
    if (input[49] >= 96206.59)
    {
        var40 = -0.048169516;
    }
    else
    {
        if (input[28] >= 19.41603)
        {
            if (input[28] >= 232.2939)
            {
                var40 = 0.0005038273;
            }
            else
            {
                var40 = 0.017884705;
            }
        }
        else
        {
            if (input[28] >= 16.706106)
            {
                var40 = -0.055730987;
            }
            else
            {
                var40 = -0.0050116056;
            }
        }
    }
    double var41;
    if (input[56] >= 92.5)
    {
        if (input[49] >= 95656.75)
        {
            if (input[7] >= 3.0480957)
            {
                var41 = 0.03977924;
            }
            else
            {
                var41 = 0.00034987007;
            }
        }
        else
        {
            if (input[42] >= 27.455)
            {
                var41 = 0.004721855;
            }
            else
            {
                var41 = 0.041252386;
            }
        }
    }
    else
    {
        if (input[42] >= 27.485)
        {
            if (input[21] >= 498.03436)
            {
                var41 = -0.025418658;
            }
            else
            {
                var41 = -0.058859434;
            }
        }
        else
        {
            if (input[42] >= 25.3)
            {
                var41 = -0.007140162;
            }
            else
            {
                var41 = 0.039457787;
            }
        }
    }
    double var42;
    if (input[56] >= 92.5)
    {
        if (input[49] >= 95656.75)
        {
            if (input[42] >= 26.36)
            {
                var42 = -0.009591265;
            }
            else
            {
                var42 = 0.010748836;
            }
        }
        else
        {
            if (input[42] >= 27.285)
            {
                var42 = 0.009518649;
            }
            else
            {
                var42 = 0.04928763;
            }
        }
    }
    else
    {
        if (input[42] >= 27.485)
        {
            if (input[21] >= 498.03436)
            {
                var42 = -0.024465974;
            }
            else
            {
                var42 = -0.058370765;
            }
        }
        else
        {
            if (input[28] >= 76.63359)
            {
                var42 = 0.013240146;
            }
            else
            {
                var42 = -0.024025818;
            }
        }
    }
    double var43;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[28] >= 207.1565)
            {
                var43 = -0.003616411;
            }
            else
            {
                var43 = 0.015549898;
            }
        }
        else
        {
            if (input[42] >= 25.85)
            {
                var43 = 0.066372976;
            }
            else
            {
                var43 = 0.028075714;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var43 = -0.055358756;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var43 = -0.011139552;
            }
            else
            {
                var43 = 0.036513366;
            }
        }
    }
    double var44;
    if (input[49] >= 96206.59)
    {
        var44 = -0.04744954;
    }
    else
    {
        if (input[28] >= 7.435115)
        {
            if (input[49] >= 96088.484)
            {
                var44 = 0.023539683;
            }
            else
            {
                var44 = 0.003559999;
            }
        }
        else
        {
            if (input[7] >= 1.6367188)
            {
                var44 = -0.03730017;
            }
            else
            {
                var44 = 0.013137765;
            }
        }
    }
    double var45;
    if (input[56] >= 113.5)
    {
        if (input[42] >= 26.36)
        {
            if (input[49] >= 95740.55)
            {
                var45 = -0.023928985;
            }
            else
            {
                var45 = 0.008948641;
            }
        }
        else
        {
            if (input[42] >= 25.865002)
            {
                var45 = 0.043728195;
            }
            else
            {
                var45 = 0.009165557;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            if (input[56] >= 110.5)
            {
                var45 = 0.03583325;
            }
            else
            {
                var45 = -0.05506587;
            }
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var45 = -0.008948581;
            }
            else
            {
                var45 = 0.034602057;
            }
        }
    }
    double var46;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[28] >= 207.1565)
            {
                var46 = -0.0036153418;
            }
            else
            {
                var46 = 0.014094121;
            }
        }
        else
        {
            if (input[7] >= 0.76538086)
            {
                var46 = 0.051918965;
            }
            else
            {
                var46 = -0.011613372;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var46 = -0.05475703;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var46 = -0.010677198;
            }
            else
            {
                var46 = 0.032783058;
            }
        }
    }
    double var47;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[28] >= 207.1565)
            {
                var47 = -0.0033100427;
            }
            else
            {
                var47 = 0.013479026;
            }
        }
        else
        {
            if (input[42] >= 25.85)
            {
                var47 = 0.061829295;
            }
            else
            {
                var47 = 0.023662327;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var47 = -0.054499786;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var47 = -0.010277099;
            }
            else
            {
                var47 = 0.030599702;
            }
        }
    }
    double var48;
    if (input[28] >= 19.446564)
    {
        if (input[28] >= 232.2939)
        {
            if (input[7] >= 3.105957)
            {
                var48 = 0.04503432;
            }
            else
            {
                var48 = -0.0037787047;
            }
        }
        else
        {
            if (input[56] >= 115.5)
            {
                var48 = 0.02456411;
            }
            else
            {
                var48 = -0.006540809;
            }
        }
    }
    else
    {
        if (input[28] >= 16.706106)
        {
            if (input[0] >= 7.9057617)
            {
                var48 = 0.01917266;
            }
            else
            {
                var48 = -0.06425282;
            }
        }
        else
        {
            if (input[14] >= 0.7104492)
            {
                var48 = 0.0068040504;
            }
            else
            {
                var48 = -0.026440306;
            }
        }
    }
    double var49;
    if (input[28] >= 7.3244276)
    {
        if (input[7] >= 2.178711)
        {
            if (input[0] >= 0.52319336)
            {
                var49 = 0.0069023483;
            }
            else
            {
                var49 = 0.030844284;
            }
        }
        else
        {
            if (input[14] >= 7.5686035)
            {
                var49 = 0.00867494;
            }
            else
            {
                var49 = -0.008046498;
            }
        }
    }
    else
    {
        if (input[21] >= 25.255726)
        {
            if (input[35] >= 485.83972)
            {
                var49 = 0.021172216;
            }
            else
            {
                var49 = -0.022737904;
            }
        }
        else
        {
            if (input[14] >= 7.796631)
            {
                var49 = 0.004233861;
            }
            else
            {
                var49 = -0.062313672;
            }
        }
    }
    double var50;
    if (input[0] >= 0.25268555)
    {
        if (input[28] >= 35.290077)
        {
            if (input[21] >= 28.748093)
            {
                var50 = -0.0015320726;
            }
            else
            {
                var50 = 0.015051275;
            }
        }
        else
        {
            if (input[35] >= 479.12213)
            {
                var50 = 0.008959697;
            }
            else
            {
                var50 = -0.022945104;
            }
        }
    }
    else
    {
        if (input[35] >= 54.767174)
        {
            if (input[7] >= 2.116455)
            {
                var50 = 0.036113065;
            }
            else
            {
                var50 = -0.013822912;
            }
        }
        else
        {
            if (input[35] >= 19.26336)
            {
                var50 = 0.06010505;
            }
            else
            {
                var50 = 0.013266335;
            }
        }
    }
    double var51;
    if (input[14] >= 7.805908)
    {
        if (input[42] >= 25.165)
        {
            if (input[35] >= 12.091602)
            {
                var51 = 0.012948331;
            }
            else
            {
                var51 = 0.04862214;
            }
        }
        else
        {
            if (input[7] >= 1.6816406)
            {
                var51 = 0.008932794;
            }
            else
            {
                var51 = -0.07289015;
            }
        }
    }
    else
    {
        if (input[7] >= 2.9465332)
        {
            if (input[49] >= 95030.83)
            {
                var51 = 0.034431;
            }
            else
            {
                var51 = -0.029283298;
            }
        }
        else
        {
            if (input[7] >= 1.2565918)
            {
                var51 = -0.0055096624;
            }
            else
            {
                var51 = 0.024551837;
            }
        }
    }
    double var52;
    if (input[28] >= 7.435115)
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 24.73)
            {
                var52 = 0.0063082734;
            }
            else
            {
                var52 = 0.061193522;
            }
        }
        else
        {
            if (input[42] >= 27.515)
            {
                var52 = -0.045450922;
            }
            else
            {
                var52 = -0.00017134233;
            }
        }
    }
    else
    {
        if (input[7] >= 1.6359863)
        {
            if (input[28] >= 4.0343513)
            {
                var52 = -0.057828575;
            }
            else
            {
                var52 = -0.013172853;
            }
        }
        else
        {
            if (input[14] >= 7.4265137)
            {
                var52 = 0.038473077;
            }
            else
            {
                var52 = -0.046928424;
            }
        }
    }
    double var53;
    if (input[14] >= 7.805908)
    {
        if (input[42] >= 25.165)
        {
            if (input[35] >= 12.091602)
            {
                var53 = 0.012269014;
            }
            else
            {
                var53 = 0.045707133;
            }
        }
        else
        {
            if (input[7] >= 1.6816406)
            {
                var53 = 0.0076994123;
            }
            else
            {
                var53 = -0.07060647;
            }
        }
    }
    else
    {
        if (input[7] >= 2.1479492)
        {
            if (input[35] >= 434.58014)
            {
                var53 = 0.025758544;
            }
            else
            {
                var53 = -0.0019868896;
            }
        }
        else
        {
            if (input[7] >= 1.2565918)
            {
                var53 = -0.009251625;
            }
            else
            {
                var53 = 0.023066344;
            }
        }
    }
    double var54;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.3818359)
        {
            if (input[28] >= 207.1565)
            {
                var54 = -0.0056774965;
            }
            else
            {
                var54 = 0.011368698;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var54 = 0.047714457;
            }
            else
            {
                var54 = 0.002850416;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var54 = -0.053904504;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var54 = -0.010624228;
            }
            else
            {
                var54 = 0.02955844;
            }
        }
    }
    double var55;
    if (input[28] >= 7.3244276)
    {
        if (input[7] >= 2.178711)
        {
            if (input[21] >= 88.74046)
            {
                var55 = -0.000047761227;
            }
            else
            {
                var55 = 0.021146318;
            }
        }
        else
        {
            if (input[14] >= 7.5686035)
            {
                var55 = 0.007524258;
            }
            else
            {
                var55 = -0.0077933893;
            }
        }
    }
    else
    {
        if (input[21] >= 25.255726)
        {
            if (input[35] >= 485.83972)
            {
                var55 = 0.021517357;
            }
            else
            {
                var55 = -0.021264067;
            }
        }
        else
        {
            if (input[21] >= 7.5610685)
            {
                var55 = -0.068255566;
            }
            else
            {
                var55 = -0.019686643;
            }
        }
    }
    double var56;
    if (input[42] >= 26.195)
    {
        if (input[49] >= 95758.33)
        {
            if (input[7] >= 2.9465332)
            {
                var56 = 0.05400349;
            }
            else
            {
                var56 = -0.029474566;
            }
        }
        else
        {
            if (input[7] >= 1.4633789)
            {
                var56 = 0.0011901115;
            }
            else
            {
                var56 = 0.04082394;
            }
        }
    }
    else
    {
        if (input[56] >= 119.5)
        {
            if (input[56] >= 192.5)
            {
                var56 = -0.015816672;
            }
            else
            {
                var56 = 0.033517778;
            }
        }
        else
        {
            if (input[42] >= 26.125)
            {
                var56 = 0.074806795;
            }
            else
            {
                var56 = -0.0055366117;
            }
        }
    }
    double var57;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[56] >= 159.5)
            {
                var57 = -0.018612398;
            }
            else
            {
                var57 = 0.006755373;
            }
        }
        else
        {
            if (input[42] >= 25.974998)
            {
                var57 = 0.059785582;
            }
            else
            {
                var57 = 0.021832244;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var57 = -0.053780247;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var57 = -0.01016578;
            }
            else
            {
                var57 = 0.026465816;
            }
        }
    }
    double var58;
    if (input[42] >= 26.195)
    {
        if (input[49] >= 95758.33)
        {
            if (input[7] >= 2.9465332)
            {
                var58 = 0.052183624;
            }
            else
            {
                var58 = -0.028183684;
            }
        }
        else
        {
            if (input[7] >= 1.4633789)
            {
                var58 = 0.00083884335;
            }
            else
            {
                var58 = 0.03840762;
            }
        }
    }
    else
    {
        if (input[42] >= 25.915)
        {
            if (input[21] >= 486.41986)
            {
                var58 = 0.06382744;
            }
            else
            {
                var58 = 0.020734845;
            }
        }
        else
        {
            if (input[0] >= 0.5270996)
            {
                var58 = -0.0058314423;
            }
            else
            {
                var58 = 0.015923792;
            }
        }
    }
    double var59;
    if (input[28] >= 19.446564)
    {
        if (input[28] >= 232.2939)
        {
            if (input[49] >= 95644.05)
            {
                var59 = -0.007875462;
            }
            else
            {
                var59 = 0.020297443;
            }
        }
        else
        {
            if (input[7] >= 1.7243652)
            {
                var59 = 0.022972392;
            }
            else
            {
                var59 = -0.005779709;
            }
        }
    }
    else
    {
        if (input[35] >= 489.2481)
        {
            if (input[21] >= 492.68323)
            {
                var59 = -0.043654904;
            }
            else
            {
                var59 = 0.03662351;
            }
        }
        else
        {
            if (input[28] >= 17.09542)
            {
                var59 = -0.06687724;
            }
            else
            {
                var59 = -0.014492735;
            }
        }
    }
    double var60;
    if (input[0] >= 0.016845703)
    {
        if (input[42] >= 26.195)
        {
            if (input[49] >= 95758.33)
            {
                var60 = -0.022704413;
            }
            else
            {
                var60 = 0.0042790775;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var60 = 0.023049217;
            }
            else
            {
                var60 = -0.002207601;
            }
        }
    }
    else
    {
        if (input[14] >= 7.914551)
        {
            var60 = -0.012469302;
        }
        else
        {
            if (input[49] >= 96106.266)
            {
                var60 = 0.0030982306;
            }
            else
            {
                var60 = 0.06697438;
            }
        }
    }
    double var61;
    if (input[56] >= 226.5)
    {
        if (input[7] >= 1.3088379)
        {
            if (input[7] >= 1.8239746)
            {
                var61 = -0.0064900788;
            }
            else
            {
                var61 = -0.05498134;
            }
        }
        else
        {
            if (input[14] >= 7.85791)
            {
                var61 = -0.00019393903;
            }
            else
            {
                var61 = 0.06319008;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[49] >= 95028.28)
            {
                var61 = 0.032224726;
            }
            else
            {
                var61 = -0.01225812;
            }
        }
        else
        {
            if (input[42] >= 27.545)
            {
                var61 = -0.017492361;
            }
            else
            {
                var61 = 0.0027310078;
            }
        }
    }
    double var62;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[56] >= 159.5)
            {
                var62 = -0.017466148;
            }
            else
            {
                var62 = 0.006032243;
            }
        }
        else
        {
            if (input[42] >= 25.974998)
            {
                var62 = 0.058064062;
            }
            else
            {
                var62 = 0.019726304;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var62 = -0.053544294;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var62 = -0.009659636;
            }
            else
            {
                var62 = 0.023827182;
            }
        }
    }
    double var63;
    if (input[28] >= 7.3244276)
    {
        if (input[7] >= 2.178711)
        {
            if (input[14] >= 0.18896484)
            {
                var63 = 0.0058156876;
            }
            else
            {
                var63 = 0.031203127;
            }
        }
        else
        {
            if (input[21] >= 458.19464)
            {
                var63 = 0.0062411427;
            }
            else
            {
                var63 = -0.008881501;
            }
        }
    }
    else
    {
        if (input[21] >= 25.255726)
        {
            if (input[35] >= 485.83972)
            {
                var63 = 0.022829253;
            }
            else
            {
                var63 = -0.019565746;
            }
        }
        else
        {
            if (input[21] >= 7.5610685)
            {
                var63 = -0.06620297;
            }
            else
            {
                var63 = -0.018084465;
            }
        }
    }
    double var64;
    if (input[0] >= 0.016845703)
    {
        if (input[42] >= 26.195)
        {
            if (input[49] >= 95758.33)
            {
                var64 = -0.021778204;
            }
            else
            {
                var64 = 0.0038878217;
            }
        }
        else
        {
            if (input[42] >= 26.125)
            {
                var64 = 0.07173583;
            }
            else
            {
                var64 = 0.004336897;
            }
        }
    }
    else
    {
        if (input[14] >= 7.914551)
        {
            var64 = -0.011632679;
        }
        else
        {
            if (input[49] >= 96106.266)
            {
                var64 = 0.001929728;
            }
            else
            {
                var64 = 0.063877515;
            }
        }
    }
    double var65;
    if (input[56] >= 110.5)
    {
        if (input[42] >= 28.474998)
        {
            if (input[35] >= 491.6985)
            {
                var65 = -0.018677903;
            }
            else
            {
                var65 = 0.058507647;
            }
        }
        else
        {
            if (input[49] >= 94921.65)
            {
                var65 = 0.004918966;
            }
            else
            {
                var65 = -0.057854373;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var65 = -0.053348042;
        }
        else
        {
            if (input[56] >= 104.5)
            {
                var65 = -0.022904588;
            }
            else
            {
                var65 = 0.0069951178;
            }
        }
    }
    double var66;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.3818359)
        {
            if (input[0] >= 1.3754883)
            {
                var66 = 0.013848829;
            }
            else
            {
                var66 = -0.0029344447;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var66 = 0.042037334;
            }
            else
            {
                var66 = 0.0015267038;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var66 = -0.053024758;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var66 = -0.009403597;
            }
            else
            {
                var66 = 0.021803517;
            }
        }
    }
    double var67;
    if (input[56] >= 226.5)
    {
        if (input[7] >= 1.3088379)
        {
            if (input[7] >= 1.8239746)
            {
                var67 = -0.005617817;
            }
            else
            {
                var67 = -0.051850837;
            }
        }
        else
        {
            if (input[14] >= 7.85791)
            {
                var67 = -0.0027452498;
            }
            else
            {
                var67 = 0.061471827;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[49] >= 95028.28)
            {
                var67 = 0.030181322;
            }
            else
            {
                var67 = -0.012603185;
            }
        }
        else
        {
            if (input[42] >= 26.195)
            {
                var67 = -0.00776757;
            }
            else
            {
                var67 = 0.0061227195;
            }
        }
    }
    double var68;
    if (input[28] >= 7.3244276)
    {
        if (input[7] >= 2.178711)
        {
            if (input[14] >= 0.18896484)
            {
                var68 = 0.005317235;
            }
            else
            {
                var68 = 0.029531008;
            }
        }
        else
        {
            if (input[21] >= 458.19464)
            {
                var68 = 0.0056195343;
            }
            else
            {
                var68 = -0.008635809;
            }
        }
    }
    else
    {
        if (input[21] >= 25.255726)
        {
            if (input[35] >= 485.83972)
            {
                var68 = 0.022724358;
            }
            else
            {
                var68 = -0.01902035;
            }
        }
        else
        {
            if (input[21] >= 7.5610685)
            {
                var68 = -0.06410935;
            }
            else
            {
                var68 = -0.017074635;
            }
        }
    }
    double var69;
    if (input[42] >= 26.195)
    {
        if (input[49] >= 95740.55)
        {
            if (input[7] >= 2.9465332)
            {
                var69 = 0.052725803;
            }
            else
            {
                var69 = -0.023713496;
            }
        }
        else
        {
            if (input[7] >= 1.4633789)
            {
                var69 = 0.00015420129;
            }
            else
            {
                var69 = 0.034885745;
            }
        }
    }
    else
    {
        if (input[42] >= 25.915)
        {
            if (input[42] >= 26.125)
            {
                var69 = 0.068768375;
            }
            else
            {
                var69 = 0.021335779;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var69 = 0.013692646;
            }
            else
            {
                var69 = -0.0064229406;
            }
        }
    }
    double var70;
    if (input[56] >= 226.5)
    {
        if (input[56] >= 238.5)
        {
            if (input[0] >= 0.3947754)
            {
                var70 = 0.01275409;
            }
            else
            {
                var70 = -0.04035433;
            }
        }
        else
        {
            if (input[49] >= 95647.85)
            {
                var70 = -0.057050176;
            }
            else
            {
                var70 = 0.017407268;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[49] >= 95028.28)
            {
                var70 = 0.02871272;
            }
            else
            {
                var70 = -0.0124524245;
            }
        }
        else
        {
            if (input[42] >= 27.545)
            {
                var70 = -0.01626809;
            }
            else
            {
                var70 = 0.0021877633;
            }
        }
    }
    double var71;
    if (input[28] >= 19.446564)
    {
        if (input[28] >= 232.2939)
        {
            if (input[49] >= 95628.81)
            {
                var71 = -0.0074179205;
            }
            else
            {
                var71 = 0.018480241;
            }
        }
        else
        {
            if (input[21] >= 458.14886)
            {
                var71 = 0.024157135;
            }
            else
            {
                var71 = -0.0021413716;
            }
        }
    }
    else
    {
        if (input[35] >= 489.2481)
        {
            if (input[21] >= 492.68323)
            {
                var71 = -0.041548785;
            }
            else
            {
                var71 = 0.036064412;
            }
        }
        else
        {
            if (input[28] >= 17.09542)
            {
                var71 = -0.06263032;
            }
            else
            {
                var71 = -0.013143837;
            }
        }
    }
    double var72;
    if (input[7] >= 2.8327637)
    {
        if (input[49] >= 94999.09)
        {
            if (input[28] >= 73.52672)
            {
                var72 = 0.031555817;
            }
            else
            {
                var72 = -0.009019231;
            }
        }
        else
        {
            if (input[42] >= 27.33)
            {
                var72 = -0.058210094;
            }
            else
            {
                var72 = 0.048890483;
            }
        }
    }
    else
    {
        if (input[7] >= 2.80542)
        {
            if (input[35] >= 486.11832)
            {
                var72 = -0.02016814;
            }
            else
            {
                var72 = -0.08652854;
            }
        }
        else
        {
            if (input[14] >= 7.3552246)
            {
                var72 = 0.004935439;
            }
            else
            {
                var72 = -0.0066392133;
            }
        }
    }
    double var73;
    if (input[56] >= 226.5)
    {
        if (input[7] >= 1.0712891)
        {
            if (input[42] >= 25.34)
            {
                var73 = -0.010519225;
            }
            else
            {
                var73 = -0.059596416;
            }
        }
        else
        {
            var73 = 0.053640682;
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[49] >= 95028.28)
            {
                var73 = 0.027068455;
            }
            else
            {
                var73 = -0.011885281;
            }
        }
        else
        {
            if (input[42] >= 27.545)
            {
                var73 = -0.015816448;
            }
            else
            {
                var73 = 0.00198535;
            }
        }
    }
    double var74;
    if (input[28] >= 7.3244276)
    {
        if (input[7] >= 2.178711)
        {
            if (input[21] >= 88.74046)
            {
                var74 = -0.0016713688;
            }
            else
            {
                var74 = 0.01735258;
            }
        }
        else
        {
            if (input[14] >= 7.5686035)
            {
                var74 = 0.0057743615;
            }
            else
            {
                var74 = -0.007828879;
            }
        }
    }
    else
    {
        if (input[21] >= 25.255726)
        {
            if (input[35] >= 485.83972)
            {
                var74 = 0.022566048;
            }
            else
            {
                var74 = -0.017481895;
            }
        }
        else
        {
            if (input[21] >= 7.5610685)
            {
                var74 = -0.062281545;
            }
            else
            {
                var74 = -0.015854662;
            }
        }
    }
    double var75;
    if (input[0] >= 0.2644043)
    {
        if (input[0] >= 1.9448242)
        {
            if (input[42] >= 25.465)
            {
                var75 = 0.013890216;
            }
            else
            {
                var75 = -0.016699104;
            }
        }
        else
        {
            if (input[49] >= 95979.27)
            {
                var75 = 0.0063266554;
            }
            else
            {
                var75 = -0.012676959;
            }
        }
    }
    else
    {
        if (input[21] >= 12.20229)
        {
            if (input[35] >= 54.767174)
            {
                var75 = 0.0039247824;
            }
            else
            {
                var75 = 0.032250088;
            }
        }
        else
        {
            if (input[7] >= 1.8198242)
            {
                var75 = 0.011649946;
            }
            else
            {
                var75 = -0.04852155;
            }
        }
    }
    double var76;
    if (input[56] >= 148.5)
    {
        if (input[42] >= 28.474998)
        {
            if (input[42] >= 28.505001)
            {
                var76 = 0.010210542;
            }
            else
            {
                var76 = 0.09289121;
            }
        }
        else
        {
            if (input[49] >= 94921.65)
            {
                var76 = -0.009787685;
            }
            else
            {
                var76 = -0.057836957;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[42] >= 26.375)
            {
                var76 = 0.01699643;
            }
            else
            {
                var76 = 0.0762867;
            }
        }
        else
        {
            if (input[42] >= 27.545)
            {
                var76 = -0.015292567;
            }
            else
            {
                var76 = 0.0018509986;
            }
        }
    }
    double var77;
    if (input[56] >= 110.5)
    {
        if (input[42] >= 28.474998)
        {
            if (input[35] >= 491.6985)
            {
                var77 = -0.018203467;
            }
            else
            {
                var77 = 0.051561374;
            }
        }
        else
        {
            if (input[49] >= 94921.65)
            {
                var77 = 0.0036442284;
            }
            else
            {
                var77 = -0.05628565;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var77 = -0.0523086;
        }
        else
        {
            if (input[49] >= 94968.625)
            {
                var77 = -0.009328306;
            }
            else
            {
                var77 = 0.02081973;
            }
        }
    }
    double var78;
    if (input[21] >= 486.3168)
    {
        if (input[21] >= 496.12976)
        {
            if (input[28] >= 420.73285)
            {
                var78 = -0.027992899;
            }
            else
            {
                var78 = 0.0066836397;
            }
        }
        else
        {
            if (input[0] >= 7.918213)
            {
                var78 = 0.06779825;
            }
            else
            {
                var78 = 0.0126169985;
            }
        }
    }
    else
    {
        if (input[0] >= 0.036865234)
        {
            if (input[49] >= 96078.33)
            {
                var78 = 0.012491608;
            }
            else
            {
                var78 = -0.005087578;
            }
        }
        else
        {
            if (input[35] >= 258.6107)
            {
                var78 = -0.0042145485;
            }
            else
            {
                var78 = 0.056628335;
            }
        }
    }
    double var79;
    if (input[42] >= 25.045)
    {
        if (input[42] >= 26.195)
        {
            if (input[49] >= 95740.55)
            {
                var79 = -0.018119778;
            }
            else
            {
                var79 = 0.0042826794;
            }
        }
        else
        {
            if (input[56] >= 124.5)
            {
                var79 = 0.03292582;
            }
            else
            {
                var79 = 0.0029152522;
            }
        }
    }
    else
    {
        if (input[35] >= 24.458015)
        {
            if (input[42] >= 24.73)
            {
                var79 = -0.038544297;
            }
            else
            {
                var79 = 0.0065559745;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var79 = 0.06951152;
            }
            else
            {
                var79 = -0.004411973;
            }
        }
    }
    double var80;
    if (input[56] >= 148.5)
    {
        if (input[7] >= 2.0412598)
        {
            if (input[7] >= 3.1140137)
            {
                var80 = -0.046231717;
            }
            else
            {
                var80 = 0.01876529;
            }
        }
        else
        {
            if (input[7] >= 1.0712891)
            {
                var80 = -0.027848024;
            }
            else
            {
                var80 = 0.054202646;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[42] >= 26.375)
            {
                var80 = 0.016133396;
            }
            else
            {
                var80 = 0.0734519;
            }
        }
        else
        {
            if (input[49] >= 95618.65)
            {
                var80 = -0.003951875;
            }
            else
            {
                var80 = 0.0125030745;
            }
        }
    }
    double var81;
    if (input[7] >= 1.432373)
    {
        if (input[7] >= 1.572998)
        {
            if (input[14] >= 0.09375)
            {
                var81 = -0.00065113255;
            }
            else
            {
                var81 = 0.02078066;
            }
        }
        else
        {
            if (input[49] >= 95628.81)
            {
                var81 = -0.031158505;
            }
            else
            {
                var81 = 0.012801512;
            }
        }
    }
    else
    {
        if (input[21] >= 467.03436)
        {
            if (input[49] >= 95758.33)
            {
                var81 = 0.011466583;
            }
            else
            {
                var81 = 0.057092812;
            }
        }
        else
        {
            if (input[21] >= 9.244274)
            {
                var81 = -0.02027986;
            }
            else
            {
                var81 = 0.048607226;
            }
        }
    }
    double var82;
    if (input[28] >= 7.3244276)
    {
        if (input[14] >= 0.09375)
        {
            if (input[14] >= 7.394043)
            {
                var82 = 0.0046707136;
            }
            else
            {
                var82 = -0.007449823;
            }
        }
        else
        {
            if (input[56] >= 134.5)
            {
                var82 = 0.042903833;
            }
            else
            {
                var82 = 0.001234332;
            }
        }
    }
    else
    {
        if (input[28] >= 4.0305343)
        {
            if (input[28] >= 6.0305347)
            {
                var82 = -0.00987309;
            }
            else
            {
                var82 = -0.05611623;
            }
        }
        else
        {
            if (input[28] >= 2.9312978)
            {
                var82 = 0.047345266;
            }
            else
            {
                var82 = -0.0144463;
            }
        }
    }
    double var83;
    if (input[56] >= 148.5)
    {
        if (input[42] >= 28.474998)
        {
            if (input[49] >= 94674.125)
            {
                var83 = 0.04923352;
            }
            else
            {
                var83 = -0.03455646;
            }
        }
        else
        {
            if (input[49] >= 94917.84)
            {
                var83 = -0.009971355;
            }
            else
            {
                var83 = -0.05776137;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[42] >= 26.375)
            {
                var83 = 0.01502535;
            }
            else
            {
                var83 = 0.070652194;
            }
        }
        else
        {
            if (input[42] >= 27.545)
            {
                var83 = -0.014502506;
            }
            else
            {
                var83 = 0.0017957885;
            }
        }
    }
    double var84;
    if (input[7] >= 2.8327637)
    {
        if (input[49] >= 94999.09)
        {
            if (input[28] >= 440.93127)
            {
                var84 = 0.041584775;
            }
            else
            {
                var84 = 0.005054771;
            }
        }
        else
        {
            if (input[42] >= 27.33)
            {
                var84 = -0.05610763;
            }
            else
            {
                var84 = 0.046186578;
            }
        }
    }
    else
    {
        if (input[7] >= 2.80542)
        {
            if (input[35] >= 486.11832)
            {
                var84 = -0.019760242;
            }
            else
            {
                var84 = -0.08113836;
            }
        }
        else
        {
            if (input[49] >= 95656.75)
            {
                var84 = -0.0033112534;
            }
            else
            {
                var84 = 0.009969938;
            }
        }
    }
    double var85;
    if (input[7] >= 1.432373)
    {
        if (input[7] >= 1.572998)
        {
            if (input[7] >= 1.6228027)
            {
                var85 = -0.000112095986;
            }
            else
            {
                var85 = 0.02924092;
            }
        }
        else
        {
            if (input[49] >= 95628.81)
            {
                var85 = -0.029772276;
            }
            else
            {
                var85 = 0.011449025;
            }
        }
    }
    else
    {
        if (input[21] >= 467.03436)
        {
            if (input[14] >= 7.953125)
            {
                var85 = -0.038996365;
            }
            else
            {
                var85 = 0.034541633;
            }
        }
        else
        {
            if (input[21] >= 9.244274)
            {
                var85 = -0.019425858;
            }
            else
            {
                var85 = 0.04652456;
            }
        }
    }
    double var86;
    if (input[7] >= 2.178711)
    {
        if (input[14] >= 0.18896484)
        {
            if (input[14] >= 0.24316406)
            {
                var86 = 0.0051995036;
            }
            else
            {
                var86 = -0.05746255;
            }
        }
        else
        {
            if (input[35] >= 467.2748)
            {
                var86 = 0.046240505;
            }
            else
            {
                var86 = 0.014626264;
            }
        }
    }
    else
    {
        if (input[14] >= 7.5686035)
        {
            if (input[56] >= 221.5)
            {
                var86 = -0.030981833;
            }
            else
            {
                var86 = 0.0074879746;
            }
        }
        else
        {
            if (input[42] >= 25.79)
            {
                var86 = -0.014567743;
            }
            else
            {
                var86 = 0.0043999455;
            }
        }
    }
    double var87;
    if (input[7] >= 1.432373)
    {
        if (input[7] >= 1.572998)
        {
            if (input[28] >= 232.2939)
            {
                var87 = -0.00467505;
            }
            else
            {
                var87 = 0.008207943;
            }
        }
        else
        {
            if (input[49] >= 95628.81)
            {
                var87 = -0.02828866;
            }
            else
            {
                var87 = 0.01115948;
            }
        }
    }
    else
    {
        if (input[21] >= 467.03436)
        {
            if (input[14] >= 7.953125)
            {
                var87 = -0.037279148;
            }
            else
            {
                var87 = 0.033213347;
            }
        }
        else
        {
            if (input[21] >= 9.244274)
            {
                var87 = -0.01825974;
            }
            else
            {
                var87 = 0.044726696;
            }
        }
    }
    double var88;
    if (input[42] >= 26.195)
    {
        if (input[49] >= 95758.33)
        {
            if (input[7] >= 2.9465332)
            {
                var88 = 0.047019176;
            }
            else
            {
                var88 = -0.022062605;
            }
        }
        else
        {
            if (input[7] >= 1.4633789)
            {
                var88 = -0.0008591753;
            }
            else
            {
                var88 = 0.031453904;
            }
        }
    }
    else
    {
        if (input[42] >= 26.125)
        {
            if (input[49] >= 95932.3)
            {
                var88 = 0.079741225;
            }
            else
            {
                var88 = -0.029852305;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var88 = 0.018279552;
            }
            else
            {
                var88 = -0.0067777373;
            }
        }
    }
    double var89;
    if (input[56] >= 148.5)
    {
        if (input[7] >= 1.9899902)
        {
            if (input[56] >= 151.5)
            {
                var89 = 0.014600538;
            }
            else
            {
                var89 = -0.0578398;
            }
        }
        else
        {
            if (input[7] >= 1.0712891)
            {
                var89 = -0.02786157;
            }
            else
            {
                var89 = 0.052790757;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[42] >= 26.375)
            {
                var89 = 0.013949548;
            }
            else
            {
                var89 = 0.0682323;
            }
        }
        else
        {
            if (input[42] >= 27.545)
            {
                var89 = -0.014555434;
            }
            else
            {
                var89 = 0.0017200897;
            }
        }
    }
    double var90;
    if (input[14] >= 0.09375)
    {
        if (input[14] >= 7.394043)
        {
            if (input[42] >= 25.154999)
            {
                var90 = 0.0063237855;
            }
            else
            {
                var90 = -0.022039667;
            }
        }
        else
        {
            if (input[49] >= 95964.03)
            {
                var90 = 0.004370113;
            }
            else
            {
                var90 = -0.017949035;
            }
        }
    }
    else
    {
        if (input[56] >= 134.5)
        {
            if (input[56] >= 147.0)
            {
                var90 = 0.00068479835;
            }
            else
            {
                var90 = 0.0563855;
            }
        }
        else
        {
            if (input[42] >= 27.705)
            {
                var90 = -0.048131038;
            }
            else
            {
                var90 = 0.00762868;
            }
        }
    }
    double var91;
    if (input[28] >= 7.3244276)
    {
        if (input[14] >= 0.09375)
        {
            if (input[7] >= 1.3818359)
            {
                var91 = -0.0020526059;
            }
            else
            {
                var91 = 0.014250693;
            }
        }
        else
        {
            if (input[0] >= 0.51049805)
            {
                var91 = 0.0000017659903;
            }
            else
            {
                var91 = 0.036495876;
            }
        }
    }
    else
    {
        if (input[21] >= 25.255726)
        {
            if (input[35] >= 485.83972)
            {
                var91 = 0.022998368;
            }
            else
            {
                var91 = -0.01590119;
            }
        }
        else
        {
            if (input[21] >= 7.5610685)
            {
                var91 = -0.059321858;
            }
            else
            {
                var91 = -0.013715716;
            }
        }
    }
    double var92;
    if (input[7] >= 2.178711)
    {
        if (input[14] >= 0.18896484)
        {
            if (input[14] >= 0.24316406)
            {
                var92 = 0.004939708;
            }
            else
            {
                var92 = -0.055349123;
            }
        }
        else
        {
            if (input[21] >= 12.900763)
            {
                var92 = 0.017148357;
            }
            else
            {
                var92 = 0.052656826;
            }
        }
    }
    else
    {
        if (input[14] >= 7.5686035)
        {
            if (input[56] >= 221.5)
            {
                var92 = -0.029550636;
            }
            else
            {
                var92 = 0.0069778897;
            }
        }
        else
        {
            if (input[14] >= 7.5356445)
            {
                var92 = -0.04706024;
            }
            else
            {
                var92 = -0.0060581737;
            }
        }
    }
    double var93;
    if (input[56] >= 110.5)
    {
        if (input[28] >= 207.1565)
        {
            if (input[7] >= 3.1306152)
            {
                var93 = 0.038170446;
            }
            else
            {
                var93 = -0.006510075;
            }
        }
        else
        {
            if (input[14] >= 7.173584)
            {
                var93 = 0.020131778;
            }
            else
            {
                var93 = -0.004038122;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var93 = -0.052135576;
        }
        else
        {
            if (input[56] >= 104.5)
            {
                var93 = -0.021270791;
            }
            else
            {
                var93 = 0.006166927;
            }
        }
    }
    double var94;
    if (input[28] >= 19.446564)
    {
        if (input[28] >= 232.2939)
        {
            if (input[49] >= 95628.81)
            {
                var94 = -0.007811812;
            }
            else
            {
                var94 = 0.01691465;
            }
        }
        else
        {
            if (input[7] >= 1.7243652)
            {
                var94 = 0.017917024;
            }
            else
            {
                var94 = -0.0069816555;
            }
        }
    }
    else
    {
        if (input[35] >= 489.2481)
        {
            if (input[21] >= 492.68323)
            {
                var94 = -0.040443175;
            }
            else
            {
                var94 = 0.035044286;
            }
        }
        else
        {
            if (input[28] >= 17.09542)
            {
                var94 = -0.057285514;
            }
            else
            {
                var94 = -0.011988131;
            }
        }
    }
    double var95;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[28] >= 207.1565)
            {
                var95 = -0.004604896;
            }
            else
            {
                var95 = 0.007442658;
            }
        }
        else
        {
            if (input[42] >= 25.974998)
            {
                var95 = 0.053596534;
            }
            else
            {
                var95 = 0.012908963;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var95 = -0.051876713;
        }
        else
        {
            if (input[35] >= 422.55344)
            {
                var95 = 0.010879352;
            }
            else
            {
                var95 = -0.013754002;
            }
        }
    }
    double var96;
    if (input[56] >= 226.5)
    {
        if (input[56] >= 247.5)
        {
            if (input[0] >= 0.5673828)
            {
                var96 = 0.048368648;
            }
            else
            {
                var96 = -0.030078951;
            }
        }
        else
        {
            if (input[14] >= 0.026123047)
            {
                var96 = -0.026963178;
            }
            else
            {
                var96 = 0.060273673;
            }
        }
    }
    else
    {
        if (input[56] >= 137.5)
        {
            if (input[49] >= 95028.28)
            {
                var96 = 0.021230776;
            }
            else
            {
                var96 = -0.012524301;
            }
        }
        else
        {
            if (input[49] >= 95618.65)
            {
                var96 = -0.0035820175;
            }
            else
            {
                var96 = 0.01103784;
            }
        }
    }
    double var97;
    if (input[42] >= 26.195)
    {
        if (input[42] >= 27.09)
        {
            if (input[42] >= 27.154999)
            {
                var97 = 0.0010633713;
            }
            else
            {
                var97 = 0.07580218;
            }
        }
        else
        {
            if (input[42] >= 26.93)
            {
                var97 = -0.07932817;
            }
            else
            {
                var97 = -0.009306426;
            }
        }
    }
    else
    {
        if (input[42] >= 26.125)
        {
            if (input[49] >= 95932.3)
            {
                var97 = 0.07703649;
            }
            else
            {
                var97 = -0.029339416;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var97 = 0.017614957;
            }
            else
            {
                var97 = -0.0067319907;
            }
        }
    }
    double var98;
    if (input[35] >= 0.30152673)
    {
        if (input[7] >= 3.46167)
        {
            if (input[14] >= 7.2580566)
            {
                var98 = -0.034144934;
            }
            else
            {
                var98 = 0.053274225;
            }
        }
        else
        {
            if (input[14] >= 7.3149414)
            {
                var98 = 0.0038878177;
            }
            else
            {
                var98 = -0.0052618026;
            }
        }
    }
    else
    {
        if (input[35] >= 0.06870229)
        {
            if (input[28] >= 467.20612)
            {
                var98 = -0.025154278;
            }
            else
            {
                var98 = -0.078311;
            }
        }
        else
        {
            var98 = 0.0219008;
        }
    }
    double var99;
    if (input[14] >= 0.09375)
    {
        if (input[14] >= 7.394043)
        {
            if (input[42] >= 25.154999)
            {
                var99 = 0.0057017957;
            }
            else
            {
                var99 = -0.021926153;
            }
        }
        else
        {
            if (input[49] >= 95964.03)
            {
                var99 = 0.0041928086;
            }
            else
            {
                var99 = -0.016404586;
            }
        }
    }
    else
    {
        if (input[56] >= 134.5)
        {
            if (input[56] >= 147.0)
            {
                var99 = 0.000026502461;
            }
            else
            {
                var99 = 0.053448047;
            }
        }
        else
        {
            if (input[42] >= 27.705)
            {
                var99 = -0.04643367;
            }
            else
            {
                var99 = 0.0072299535;
            }
        }
    }
    double var100;
    if (input[56] >= 110.5)
    {
        if (input[7] >= 1.1628418)
        {
            if (input[0] >= 1.3129883)
            {
                var100 = 0.010566672;
            }
            else
            {
                var100 = -0.0025857145;
            }
        }
        else
        {
            if (input[0] >= 1.5979004)
            {
                var100 = 0.0013320026;
            }
            else
            {
                var100 = 0.044107445;
            }
        }
    }
    else
    {
        if (input[42] >= 27.515)
        {
            var100 = -0.0516614;
        }
        else
        {
            if (input[56] >= 104.5)
            {
                var100 = -0.020691505;
            }
            else
            {
                var100 = 0.0057134465;
            }
        }
    }
    double var101;
    if (input[42] >= 29.05)
    {
        if (input[42] >= 30.564999)
        {
            if (input[56] >= 69.5)
            {
                var101 = 0.19047618;
            }
            else
            {
                var101 = -0.0503876;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var101 = 0.219611;
            }
            else
            {
                var101 = 0.11678004;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var101 = 0.23700623;
            }
            else
            {
                var101 = -0.057110544;
            }
        }
        else
        {
            var101 = -0.062423047;
        }
    }
    double var102;
    if (input[42] >= 29.05)
    {
        if (input[42] >= 30.564999)
        {
            if (input[56] >= 69.5)
            {
                var102 = 0.1629208;
            }
            else
            {
                var102 = -0.05004969;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var102 = 0.1800255;
            }
            else
            {
                var102 = 0.10157441;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var102 = 0.19367951;
            }
            else
            {
                var102 = -0.05599428;
            }
        }
        else
        {
            var102 = -0.061441034;
        }
    }
    double var103;
    if (input[42] >= 29.05)
    {
        if (input[42] >= 30.564999)
        {
            if (input[56] >= 69.5)
            {
                var103 = 0.14239807;
            }
            else
            {
                var103 = -0.04969094;
            }
        }
        else
        {
            if (input[14] >= 7.4960938)
            {
                var103 = 0.14438264;
            }
            else
            {
                var103 = 0.060442563;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var103 = 0.16514526;
            }
            else
            {
                var103 = -0.05497942;
            }
        }
        else
        {
            var103 = -0.060540687;
        }
    }
    double var104;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 95446.09)
        {
            if (input[42] >= 30.564999)
            {
                var104 = 0.04596735;
            }
            else
            {
                var104 = 0.119104244;
            }
        }
        else
        {
            var104 = -0.039828535;
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var104 = 0.14456753;
            }
            else
            {
                var104 = -0.054778613;
            }
        }
        else
        {
            var104 = -0.05971331;
        }
    }
    double var105;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 95446.09)
        {
            if (input[42] >= 30.564999)
            {
                var105 = 0.040641498;
            }
            else
            {
                var105 = 0.10577662;
            }
        }
        else
        {
            var105 = -0.038400564;
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var105 = 0.11163465;
            }
            else
            {
                var105 = -0.05887868;
            }
        }
        else
        {
            var105 = -0.05895536;
        }
    }
    double var106;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 95446.09)
        {
            if (input[42] >= 30.564999)
            {
                var106 = 0.035967328;
            }
            else
            {
                var106 = 0.095172666;
            }
        }
        else
        {
            var106 = -0.036916703;
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var106 = 0.11877396;
            }
            else
            {
                var106 = -0.05317091;
            }
        }
        else
        {
            var106 = -0.058260232;
        }
    }
    double var107;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 95446.09)
        {
            if (input[42] >= 30.564999)
            {
                var107 = 0.031831473;
            }
            else
            {
                var107 = 0.08651373;
            }
        }
        else
        {
            var107 = -0.035608403;
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var107 = 0.09360672;
            }
            else
            {
                var107 = -0.057641674;
            }
        }
        else
        {
            var107 = -0.05762728;
        }
    }
    double var108;
    if (input[42] >= 29.01)
    {
        if (input[35] >= 496.39694)
        {
            if (input[42] >= 30.560001)
            {
                var108 = 0.017762389;
            }
            else
            {
                var108 = 0.1034505;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var108 = 0.07721451;
            }
            else
            {
                var108 = 0.016483668;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var108 = 0.102397636;
            }
            else
            {
                var108 = -0.051727552;
            }
        }
        else
        {
            var108 = -0.05704611;
        }
    }
    double var109;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96535.55)
        {
            if (input[35] >= 0.8206107)
            {
                var109 = 0.11403167;
            }
            else
            {
                var109 = -0.008690561;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var109 = 0.07632571;
            }
            else
            {
                var109 = -0.04048446;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var109 = 0.0819757;
            }
            else
            {
                var109 = -0.05657096;
            }
        }
        else
        {
            var109 = -0.056516983;
        }
    }
    double var110;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96416.15)
        {
            if (input[28] >= 470.56488)
            {
                var110 = 0.09299614;
            }
            else
            {
                var110 = 0.042906668;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var110 = 0.07731938;
            }
            else
            {
                var110 = -0.068230614;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var110 = 0.09173979;
            }
            else
            {
                var110 = -0.0504011;
            }
        }
        else
        {
            var110 = -0.056025833;
        }
    }
    double var111;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96416.15)
        {
            if (input[14] >= 0.10253906)
            {
                var111 = 0.074734904;
            }
            else
            {
                var111 = -0.021921718;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var111 = 0.07190214;
            }
            else
            {
                var111 = -0.06748257;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var111 = 0.07342181;
            }
            else
            {
                var111 = -0.05564555;
            }
        }
        else
        {
            var111 = -0.05558173;
        }
    }
    double var112;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96535.55)
        {
            if (input[35] >= 0.8206107)
            {
                var112 = 0.09595584;
            }
            else
            {
                var112 = -0.014295219;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var112 = 0.06330622;
            }
            else
            {
                var112 = -0.044803943;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var112 = 0.08397471;
            }
            else
            {
                var112 = -0.049096588;
            }
        }
        else
        {
            var112 = -0.055173963;
        }
    }
    double var113;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96416.15)
        {
            if (input[28] >= 470.56488)
            {
                var113 = 0.07940584;
            }
            else
            {
                var113 = 0.033150997;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var113 = 0.06442396;
            }
            else
            {
                var113 = -0.06875998;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var113 = 0.06685396;
            }
            else
            {
                var113 = -0.054837745;
            }
        }
        else
        {
            var113 = -0.054795187;
        }
    }
    double var114;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96416.15)
        {
            if (input[0] >= 7.4016113)
            {
                var114 = 0.06897786;
            }
            else
            {
                var114 = 0.0148392515;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var114 = 0.06088182;
            }
            else
            {
                var114 = -0.06765435;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var114 = 0.06302225;
            }
            else
            {
                var114 = -0.054455485;
            }
        }
        else
        {
            var114 = -0.054446828;
        }
    }
    double var115;
    if (input[42] >= 29.01)
    {
        if (input[35] >= 496.39694)
        {
            if (input[42] >= 30.560001)
            {
                var115 = 0.000045785142;
            }
            else
            {
                var115 = 0.07274111;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var115 = 0.048863433;
            }
            else
            {
                var115 = -0.0010289478;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96732.42)
            {
                var115 = 0.07607212;
            }
            else
            {
                var115 = -0.047486033;
            }
        }
        else
        {
            var115 = -0.054124363;
        }
    }
    double var116;
    if (input[42] >= 29.01)
    {
        if (input[49] >= 96535.55)
        {
            if (input[35] >= 0.8206107)
            {
                var116 = 0.08388453;
            }
            else
            {
                var116 = -0.018621264;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var116 = 0.05149103;
            }
            else
            {
                var116 = -0.04819296;
            }
        }
    }
    else
    {
        if (input[42] >= 27.845001)
        {
            if (input[49] >= 96708.28)
            {
                var116 = 0.058350544;
            }
            else
            {
                var116 = -0.053803355;
            }
        }
        else
        {
            var116 = -0.053831425;
        }
    }
    double var117;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 95567.95)
        {
            if (input[42] >= 28.285)
            {
                var117 = 0.024503253;
            }
            else
            {
                var117 = 0.080458395;
            }
        }
        else
        {
            var117 = -0.05305956;
        }
    }
    else
    {
        var117 = -0.053563185;
    }
    double var118;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 95567.95)
        {
            if (input[42] >= 28.285)
            {
                var118 = 0.022653768;
            }
            else
            {
                var118 = 0.078351654;
            }
        }
        else
        {
            var118 = -0.0527623;
        }
    }
    else
    {
        var118 = -0.05331036;
    }
    double var119;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 95567.95)
        {
            if (input[42] >= 28.285)
            {
                var119 = 0.02105432;
            }
            else
            {
                var119 = 0.07618806;
            }
        }
        else
        {
            var119 = -0.052450854;
        }
    }
    else
    {
        var119 = -0.053079493;
    }
    double var120;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 95567.95)
        {
            if (input[42] >= 28.285)
            {
                var120 = 0.019464934;
            }
            else
            {
                var120 = 0.07449629;
            }
        }
        else
        {
            var120 = -0.052171327;
        }
    }
    else
    {
        var120 = -0.052862942;
    }
    double var121;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 95567.95)
        {
            if (input[42] >= 28.285)
            {
                var121 = 0.018404167;
            }
            else
            {
                var121 = 0.07248283;
            }
        }
        else
        {
            var121 = -0.051898163;
        }
    }
    else
    {
        var121 = -0.052661885;
    }
    double var122;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 95567.95)
        {
            if (input[42] >= 28.285)
            {
                var122 = 0.01690292;
            }
            else
            {
                var122 = 0.071052894;
            }
        }
        else
        {
            var122 = -0.05163921;
        }
    }
    else
    {
        var122 = -0.052472867;
    }
    double var123;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var123 = 0.015861848;
            }
            else
            {
                var123 = 0.06961336;
            }
        }
        else
        {
            var123 = -0.050406016;
        }
    }
    else
    {
        var123 = -0.052467346;
    }
    double var124;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var124 = 0.0145438565;
            }
            else
            {
                var124 = 0.06840589;
            }
        }
        else
        {
            var124 = -0.050147146;
        }
    }
    else
    {
        var124 = -0.052294172;
    }
    double var125;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var125 = 0.01333535;
            }
            else
            {
                var125 = 0.06739309;
            }
        }
        else
        {
            var125 = -0.049888298;
        }
    }
    else
    {
        var125 = -0.052133262;
    }
    double var126;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var126 = 0.012415021;
            }
            else
            {
                var126 = 0.066188514;
            }
        }
        else
        {
            var126 = -0.049642477;
        }
    }
    else
    {
        var126 = -0.051979817;
    }
    double var127;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var127 = 0.011223101;
            }
            else
            {
                var127 = 0.065275095;
            }
        }
        else
        {
            var127 = -0.049383685;
        }
    }
    else
    {
        var127 = -0.051833183;
    }
    double var128;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var128 = 0.010232208;
            }
            else
            {
                var128 = 0.06436461;
            }
        }
        else
        {
            var128 = -0.049125224;
        }
    }
    else
    {
        var128 = -0.05169619;
    }
    double var129;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var129 = 0.009733064;
            }
            else
            {
                var129 = 0.06271822;
            }
        }
        else
        {
            var129 = -0.048881307;
        }
    }
    else
    {
        var129 = -0.0515674;
    }
    double var130;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var130 = 0.009084805;
            }
            else
            {
                var130 = 0.061796434;
            }
        }
        else
        {
            var130 = -0.04862271;
        }
    }
    else
    {
        var130 = -0.05144232;
    }
    double var131;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var131 = 0.008156772;
            }
            else
            {
                var131 = 0.061116863;
            }
        }
        else
        {
            var131 = -0.048342634;
        }
    }
    else
    {
        var131 = -0.051325273;
    }
    double var132;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var132 = 0.0073014894;
            }
            else
            {
                var132 = 0.060475852;
            }
        }
        else
        {
            var132 = -0.04805432;
        }
    }
    else
    {
        var132 = -0.051212806;
    }
    double var133;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var133 = 0.006863836;
            }
            else
            {
                var133 = 0.05908466;
            }
        }
        else
        {
            var133 = -0.04777966;
        }
    }
    else
    {
        var133 = -0.05110559;
    }
    double var134;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var134 = 0.006432256;
            }
            else
            {
                var134 = 0.058338083;
            }
        }
        else
        {
            var134 = -0.047485445;
        }
    }
    else
    {
        var134 = -0.051002633;
    }
    double var135;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var135 = 0.0058072787;
            }
            else
            {
                var135 = 0.05774912;
            }
        }
        else
        {
            var135 = -0.04716577;
        }
    }
    else
    {
        var135 = -0.050903637;
    }
    double var136;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var136 = 0.005137924;
            }
            else
            {
                var136 = 0.05724078;
            }
        }
        else
        {
            var136 = -0.046826806;
        }
    }
    else
    {
        var136 = -0.05080821;
    }
    double var137;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var137 = 0.004827459;
            }
            else
            {
                var137 = 0.056570094;
            }
        }
        else
        {
            var137 = -0.04649203;
        }
    }
    else
    {
        var137 = -0.0507158;
    }
    double var138;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var138 = 0.004373434;
            }
            else
            {
                var138 = 0.05613665;
            }
        }
        else
        {
            var138 = -0.046117347;
        }
    }
    else
    {
        var138 = -0.050626367;
    }
    double var139;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var139 = 0.004162746;
            }
            else
            {
                var139 = 0.055008013;
            }
        }
        else
        {
            var139 = -0.04575564;
        }
    }
    else
    {
        var139 = -0.050539266;
    }
    double var140;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var140 = 0.0037502889;
            }
            else
            {
                var140 = 0.05453659;
            }
        }
        else
        {
            var140 = -0.045355704;
        }
    }
    else
    {
        var140 = -0.050454196;
    }
    double var141;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var141 = 0.0032614265;
            }
            else
            {
                var141 = 0.05413291;
            }
        }
        else
        {
            var141 = -0.04492863;
        }
    }
    else
    {
        var141 = -0.05037094;
    }
    double var142;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 28.869999)
        {
            if (input[49] >= 96535.55)
            {
                var142 = 0.05678609;
            }
            else
            {
                var142 = 0.0039739353;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var142 = -0.05751654;
            }
            else
            {
                var142 = 0.013289399;
            }
        }
    }
    else
    {
        var142 = -0.050289333;
    }
    double var143;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var143 = 0.0027607072;
            }
            else
            {
                var143 = 0.053022098;
            }
        }
        else
        {
            var143 = -0.04439594;
        }
    }
    else
    {
        var143 = -0.050209053;
    }
    double var144;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var144 = 0.060383644;
            }
            else
            {
                var144 = -0.051823057;
            }
        }
        else
        {
            if (input[0] >= 7.69751)
            {
                var144 = 0.035313718;
            }
            else
            {
                var144 = -0.04364605;
            }
        }
    }
    else
    {
        var144 = -0.05012849;
    }
    double var145;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var145 = 0.0019564368;
            }
            else
            {
                var145 = 0.052769203;
            }
        }
        else
        {
            var145 = -0.043587226;
        }
    }
    else
    {
        var145 = -0.0500502;
    }
    double var146;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var146 = 0.059208572;
            }
            else
            {
                var146 = -0.050587278;
            }
        }
        else
        {
            if (input[0] >= 7.69751)
            {
                var146 = 0.034319587;
            }
            else
            {
                var146 = -0.042153593;
            }
        }
    }
    else
    {
        var146 = -0.049971286;
    }
    double var147;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var147 = 0.0014610393;
            }
            else
            {
                var147 = 0.05196445;
            }
        }
        else
        {
            var147 = -0.042745117;
        }
    }
    else
    {
        var147 = -0.049893692;
    }
    double var148;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 28.869999)
        {
            if (input[49] >= 96535.55)
            {
                var148 = 0.054075837;
            }
            else
            {
                var148 = -0.0008315017;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var148 = -0.054586735;
            }
            else
            {
                var148 = 0.016039971;
            }
        }
    }
    else
    {
        var148 = -0.04981589;
    }
    double var149;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var149 = 0.057181057;
            }
            else
            {
                var149 = -0.046139274;
            }
        }
        else
        {
            if (input[49] >= 96529.19)
            {
                var149 = 0.009702133;
            }
            else
            {
                var149 = -0.09130856;
            }
        }
    }
    else
    {
        var149 = -0.049738154;
    }
    double var150;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var150 = 0.0008528134;
            }
            else
            {
                var150 = 0.051405467;
            }
        }
        else
        {
            var150 = -0.042005558;
        }
    }
    else
    {
        var150 = -0.049660932;
    }
    double var151;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 28.869999)
        {
            if (input[49] >= 96535.55)
            {
                var151 = 0.05213062;
            }
            else
            {
                var151 = -0.0010241994;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var151 = -0.053839844;
            }
            else
            {
                var151 = 0.016900081;
            }
        }
    }
    else
    {
        var151 = -0.049582936;
    }
    double var152;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var152 = 0.056097418;
            }
            else
            {
                var152 = -0.043129567;
            }
        }
        else
        {
            if (input[49] >= 96529.19)
            {
                var152 = 0.009908774;
            }
            else
            {
                var152 = -0.08574464;
            }
        }
    }
    else
    {
        var152 = -0.049503647;
    }
    double var153;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var153 = 0.00086530903;
            }
            else
            {
                var153 = 0.050320473;
            }
        }
        else
        {
            var153 = -0.041208643;
        }
    }
    else
    {
        var153 = -0.049424347;
    }
    double var154;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 28.869999)
        {
            if (input[49] >= 96535.55)
            {
                var154 = 0.05048232;
            }
            else
            {
                var154 = -0.0019571504;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var154 = -0.052701104;
            }
            else
            {
                var154 = 0.016628388;
            }
        }
    }
    else
    {
        var154 = -0.049343035;
    }
    double var155;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var155 = 0.055003643;
            }
            else
            {
                var155 = -0.040850494;
            }
        }
        else
        {
            if (input[49] >= 96529.19)
            {
                var155 = 0.0101367375;
            }
            else
            {
                var155 = -0.08159762;
            }
        }
    }
    else
    {
        var155 = -0.049259942;
    }
    double var156;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var156 = 0.00050925504;
            }
            else
            {
                var156 = 0.049902216;
            }
        }
        else
        {
            var156 = -0.040474866;
        }
    }
    else
    {
        var156 = -0.049176972;
    }
    double var157;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 28.869999)
        {
            if (input[49] >= 96535.55)
            {
                var157 = 0.04863989;
            }
            else
            {
                var157 = -0.002253017;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var157 = -0.052044034;
            }
            else
            {
                var157 = 0.017252652;
            }
        }
    }
    else
    {
        var157 = -0.049091283;
    }
    double var158;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var158 = 0.053987194;
            }
            else
            {
                var158 = -0.038805034;
            }
        }
        else
        {
            if (input[49] >= 96529.19)
            {
                var158 = 0.010133454;
            }
            else
            {
                var158 = -0.07695418;
            }
        }
    }
    else
    {
        var158 = -0.049004342;
    }
    double var159;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var159 = 0.00003541911;
            }
            else
            {
                var159 = 0.0494418;
            }
        }
        else
        {
            var159 = -0.039708506;
        }
    }
    else
    {
        var159 = -0.04891497;
    }
    double var160;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 28.869999)
        {
            if (input[42] >= 29.225)
            {
                var160 = 0.00047443827;
            }
            else
            {
                var160 = 0.05965502;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var160 = -0.051351357;
            }
            else
            {
                var160 = 0.017805953;
            }
        }
    }
    else
    {
        var160 = -0.048823413;
    }
    double var161;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 27.83)
        {
            if (input[42] >= 28.285)
            {
                var161 = -0.00018357381;
            }
            else
            {
                var161 = 0.048925873;
            }
        }
        else
        {
            var161 = -0.03905781;
        }
    }
    else
    {
        var161 = -0.048729785;
    }
    double var162;
    if (input[49] >= 96206.59)
    {
        if (input[35] >= 496.39694)
        {
            if (input[42] >= 28.89)
            {
                var162 = 0.03423567;
            }
            else
            {
                var162 = -0.016542675;
            }
        }
        else
        {
            if (input[35] >= 3.0458016)
            {
                var162 = -0.017318448;
            }
            else
            {
                var162 = 0.015668256;
            }
        }
    }
    else
    {
        var162 = -0.048632827;
    }
    double var163;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[35] >= 496.39694)
            {
                var163 = 0.021057704;
            }
            else
            {
                var163 = -0.0038337726;
            }
        }
        else
        {
            var163 = -0.052782442;
        }
    }
    else
    {
        var163 = -0.04853412;
    }
    double var164;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96416.15)
            {
                var164 = 0.012265327;
            }
            else
            {
                var164 = -0.014268624;
            }
        }
        else
        {
            var164 = -0.051290136;
        }
    }
    else
    {
        var164 = -0.04843327;
    }
    double var165;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var165 = 0.052197855;
            }
            else
            {
                var165 = -0.036110897;
            }
        }
        else
        {
            if (input[49] >= 96529.19)
            {
                var165 = 0.010205903;
            }
            else
            {
                var165 = -0.07214018;
            }
        }
    }
    else
    {
        var165 = -0.04832835;
    }
    double var166;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[42] >= 28.869999)
            {
                var166 = 0.01232241;
            }
            else
            {
                var166 = -0.012777189;
            }
        }
        else
        {
            var166 = -0.050293095;
        }
    }
    else
    {
        var166 = -0.04822019;
    }
    double var167;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96416.15)
            {
                var167 = 0.01174405;
            }
            else
            {
                var167 = -0.015191934;
            }
        }
        else
        {
            var167 = -0.048563104;
        }
    }
    else
    {
        var167 = -0.048108492;
    }
    double var168;
    if (input[49] >= 96206.59)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var168 = 0.020582017;
            }
            else
            {
                var168 = -0.014854501;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var168 = -0.029719848;
            }
            else
            {
                var168 = 0.04508053;
            }
        }
    }
    else
    {
        var168 = -0.047993522;
    }
    double var169;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var169 = 0.015588402;
            }
            else
            {
                var169 = -0.008066277;
            }
        }
        else
        {
            var169 = -0.047183376;
        }
    }
    else
    {
        var169 = -0.04787446;
    }
    double var170;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 488.57632)
        {
            if (input[42] >= 28.869999)
            {
                var170 = 0.028157804;
            }
            else
            {
                var170 = -0.016139077;
            }
        }
        else
        {
            if (input[7] >= 1.5163574)
            {
                var170 = -0.010644977;
            }
            else
            {
                var170 = 0.038159274;
            }
        }
    }
    else
    {
        var170 = -0.047751;
    }
    double var171;
    if (input[49] >= 96206.59)
    {
        if (input[35] >= 496.39694)
        {
            if (input[42] >= 28.89)
            {
                var171 = 0.030617625;
            }
            else
            {
                var171 = -0.014372985;
            }
        }
        else
        {
            if (input[49] >= 96535.55)
            {
                var171 = 0.010253315;
            }
            else
            {
                var171 = -0.019074993;
            }
        }
    }
    else
    {
        var171 = -0.047624107;
    }
    double var172;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var172 = 0.015848799;
            }
            else
            {
                var172 = -0.008050251;
            }
        }
        else
        {
            var172 = -0.046218116;
        }
    }
    else
    {
        var172 = -0.04749408;
    }
    double var173;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var173 = 0.008294552;
            }
            else
            {
                var173 = -0.04924889;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var173 = 0.044898268;
            }
            else
            {
                var173 = 0.011968021;
            }
        }
    }
    else
    {
        var173 = -0.047395993;
    }
    double var174;
    if (input[49] >= 96206.59)
    {
        if (input[42] >= 29.79)
        {
            if (input[56] >= 69.5)
            {
                var174 = 0.050846078;
            }
            else
            {
                var174 = -0.034790587;
            }
        }
        else
        {
            if (input[49] >= 96529.19)
            {
                var174 = 0.011235762;
            }
            else
            {
                var174 = -0.06729285;
            }
        }
    }
    else
    {
        var174 = -0.04722661;
    }
    double var175;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var175 = 0.04773094;
            }
            else
            {
                var175 = 0.0036642943;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var175 = 0.008930094;
            }
            else
            {
                var175 = -0.0630342;
            }
        }
    }
    else
    {
        var175 = -0.047131676;
    }
    double var176;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var176 = 0.016290097;
            }
            else
            {
                var176 = -0.00765433;
            }
        }
        else
        {
            var176 = -0.045568705;
        }
    }
    else
    {
        var176 = -0.046958424;
    }
    double var177;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var177 = 0.008538998;
            }
            else
            {
                var177 = -0.048792023;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var177 = 0.044303287;
            }
            else
            {
                var177 = 0.013463648;
            }
        }
    }
    else
    {
        var177 = -0.04684447;
    }
    double var178;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var178 = 0.016608436;
            }
            else
            {
                var178 = -0.008124555;
            }
        }
        else
        {
            var178 = -0.04440856;
        }
    }
    else
    {
        var178 = -0.046655316;
    }
    double var179;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var179 = 0.00785718;
            }
            else
            {
                var179 = -0.048318382;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var179 = 0.043857165;
            }
            else
            {
                var179 = 0.013709647;
            }
        }
    }
    else
    {
        var179 = -0.046539154;
    }
    double var180;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var180 = 0.016477464;
            }
            else
            {
                var180 = -0.007862755;
            }
        }
        else
        {
            var180 = -0.044069454;
        }
    }
    else
    {
        var180 = -0.04632993;
    }
    double var181;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var181 = 0.0074847746;
            }
            else
            {
                var181 = -0.0476129;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var181 = 0.042809986;
            }
            else
            {
                var181 = 0.013006321;
            }
        }
    }
    else
    {
        var181 = -0.046214152;
    }
    double var182;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var182 = 0.016209524;
            }
            else
            {
                var182 = -0.007487271;
            }
        }
        else
        {
            var182 = -0.043814655;
        }
    }
    else
    {
        var182 = -0.045985542;
    }
    double var183;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var183 = 0.007329957;
            }
            else
            {
                var183 = -0.04720336;
            }
        }
        else
        {
            if (input[56] >= 79.0)
            {
                var183 = 0.008831238;
            }
            else
            {
                var183 = 0.040698368;
            }
        }
    }
    else
    {
        var183 = -0.045880087;
    }
    double var184;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var184 = 0.04605073;
            }
            else
            {
                var184 = 0.0028675986;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var184 = 0.01085679;
            }
            else
            {
                var184 = -0.060239863;
            }
        }
    }
    else
    {
        var184 = -0.04567979;
    }
    double var185;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var185 = 0.01603055;
            }
            else
            {
                var185 = -0.007231743;
            }
        }
        else
        {
            var185 = -0.04335904;
        }
    }
    else
    {
        var185 = -0.04546436;
    }
    double var186;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var186 = 0.0069129183;
            }
            else
            {
                var186 = -0.04645017;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var186 = 0.041380703;
            }
            else
            {
                var186 = 0.011871132;
            }
        }
    }
    else
    {
        var186 = -0.045319036;
    }
    double var187;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var187 = 0.01652359;
            }
            else
            {
                var187 = -0.0074349376;
            }
        }
        else
        {
            var187 = -0.042322304;
        }
    }
    else
    {
        var187 = -0.045070406;
    }
    double var188;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var188 = 0.045474857;
            }
            else
            {
                var188 = 0.002173195;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var188 = 0.012246265;
            }
            else
            {
                var188 = -0.05940467;
            }
        }
    }
    else
    {
        var188 = -0.044923805;
    }
    double var189;
    if (input[49] >= 96206.59)
    {
        if (input[35] >= 496.39694)
        {
            if (input[42] >= 28.89)
            {
                var189 = 0.027486702;
            }
            else
            {
                var189 = -0.012136238;
            }
        }
        else
        {
            if (input[49] >= 96535.55)
            {
                var189 = 0.010026916;
            }
            else
            {
                var189 = -0.016799595;
            }
        }
    }
    else
    {
        var189 = -0.04468062;
    }
    double var190;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var190 = 0.006278643;
            }
            else
            {
                var190 = -0.04557853;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var190 = 0.04054955;
            }
            else
            {
                var190 = 0.012335451;
            }
        }
    }
    else
    {
        var190 = -0.044498395;
    }
    double var191;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var191 = 0.016503546;
            }
            else
            {
                var191 = -0.0072666625;
            }
        }
        else
        {
            var191 = -0.04147788;
        }
    }
    else
    {
        var191 = -0.04424364;
    }
    double var192;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var192 = 0.0062346957;
            }
            else
            {
                var192 = -0.045212295;
            }
        }
        else
        {
            if (input[56] >= 76.5)
            {
                var192 = 0.0098558;
            }
            else
            {
                var192 = 0.038660258;
            }
        }
    }
    else
    {
        var192 = -0.04406344;
    }
    double var193;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var193 = 0.016165549;
            }
            else
            {
                var193 = -0.0069323466;
            }
        }
        else
        {
            var193 = -0.040843736;
        }
    }
    else
    {
        var193 = -0.043787856;
    }
    double var194;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var194 = 0.005967275;
            }
            else
            {
                var194 = -0.044795476;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var194 = 0.03951018;
            }
            else
            {
                var194 = 0.0122037735;
            }
        }
    }
    else
    {
        var194 = -0.043617673;
    }
    double var195;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var195 = 0.0441295;
            }
            else
            {
                var195 = 0.0025742261;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var195 = 0.013076156;
            }
            else
            {
                var195 = -0.05820013;
            }
        }
    }
    else
    {
        var195 = -0.043344855;
    }
    double var196;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 493.88168)
        {
            if (input[42] >= 28.869999)
            {
                var196 = 0.026573703;
            }
            else
            {
                var196 = -0.00959738;
            }
        }
        else
        {
            if (input[49] >= 96332.33)
            {
                var196 = -0.009816031;
            }
            else
            {
                var196 = 0.026945341;
            }
        }
    }
    else
    {
        var196 = -0.04310177;
    }
    double var197;
    if (input[42] >= 27.845001)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var197 = 0.043560207;
            }
            else
            {
                var197 = 0.0029227838;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var197 = 0.013323364;
            }
            else
            {
                var197 = -0.057303756;
            }
        }
    }
    else
    {
        var197 = -0.042869367;
    }
    double var198;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var198 = 0.016533105;
            }
            else
            {
                var198 = -0.0070740604;
            }
        }
        else
        {
            var198 = -0.040545788;
        }
    }
    else
    {
        var198 = -0.042626508;
    }
    double var199;
    if (input[49] >= 96206.59)
    {
        if (input[28] >= 0.39312977)
        {
            if (input[49] >= 96529.19)
            {
                var199 = 0.015673375;
            }
            else
            {
                var199 = -0.0063337833;
            }
        }
        else
        {
            var199 = -0.03925574;
        }
    }
    else
    {
        var199 = -0.042346884;
    }
    double var200;
    if (input[42] >= 27.845001)
    {
        if (input[42] >= 28.215)
        {
            if (input[42] >= 29.01)
            {
                var200 = 0.006387164;
            }
            else
            {
                var200 = -0.043801602;
            }
        }
        else
        {
            if (input[49] >= 96710.83)
            {
                var200 = 0.03756111;
            }
            else
            {
                var200 = 0.012001384;
            }
        }
    }
    else
    {
        var200 = -0.042191315;
    }
    double var201;
    if (input[56] >= 81.5)
    {
        if (input[56] >= 246.5)
        {
            if (input[49] >= 96530.46)
            {
                var201 = 0.12162162;
            }
            else
            {
                var201 = -0.057093423;
            }
        }
        else
        {
            if (input[56] >= 86.5)
            {
                var201 = -0.061923977;
            }
            else
            {
                var201 = -0.033264033;
            }
        }
    }
    else
    {
        if (input[42] >= 27.415)
        {
            if (input[49] >= 96282.8)
            {
                var201 = 0.064467765;
            }
            else
            {
                var201 = -0.06023222;
            }
        }
        else
        {
            var201 = -0.06167633;
        }
    }
    double var202;
    if (input[56] >= 81.5)
    {
        if (input[56] >= 246.5)
        {
            if (input[49] >= 96530.46)
            {
                var202 = 0.10623765;
            }
            else
            {
                var202 = -0.05604006;
            }
        }
        else
        {
            if (input[56] >= 86.5)
            {
                var202 = -0.060914405;
            }
            else
            {
                var202 = -0.031887587;
            }
        }
    }
    else
    {
        if (input[42] >= 27.415)
        {
            if (input[49] >= 96282.8)
            {
                var202 = 0.05771912;
            }
            else
            {
                var202 = -0.059220787;
            }
        }
        else
        {
            var202 = -0.060649294;
        }
    }
    double var203;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var203 = 0.03170818;
            }
            else
            {
                var203 = 0.17300342;
            }
        }
        else
        {
            var203 = -0.060174473;
        }
    }
    else
    {
        var203 = -0.060569275;
    }
    double var204;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var204 = 0.029247237;
            }
            else
            {
                var204 = 0.1459877;
            }
        }
        else
        {
            var204 = -0.059266817;
        }
    }
    else
    {
        var204 = -0.0597541;
    }
    double var205;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var205 = 0.02723029;
            }
            else
            {
                var205 = 0.12648381;
            }
        }
        else
        {
            var205 = -0.058423687;
        }
    }
    else
    {
        var205 = -0.059011776;
    }
    double var206;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var206 = 0.02559707;
            }
            else
            {
                var206 = 0.11174154;
            }
        }
        else
        {
            var206 = -0.057640593;
        }
    }
    else
    {
        var206 = -0.05833744;
    }
    double var207;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var207 = 0.024051862;
            }
            else
            {
                var207 = 0.10020687;
            }
        }
        else
        {
            var207 = -0.05691365;
        }
    }
    else
    {
        var207 = -0.05772003;
    }
    double var208;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var208 = -0.008600903;
            }
            else
            {
                var208 = 0.054051228;
            }
        }
        else
        {
            var208 = -0.05623923;
        }
    }
    else
    {
        var208 = -0.05715685;
    }
    double var209;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var209 = 0.020967571;
            }
            else
            {
                var209 = 0.08532623;
            }
        }
        else
        {
            var209 = -0.055613704;
        }
    }
    else
    {
        var209 = -0.056638833;
    }
    double var210;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var210 = -0.0074595357;
            }
            else
            {
                var210 = 0.04638267;
            }
        }
        else
        {
            var210 = -0.055033524;
        }
    }
    else
    {
        var210 = -0.056163497;
    }
    double var211;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var211 = 0.018514752;
            }
            else
            {
                var211 = 0.07446606;
            }
        }
        else
        {
            var211 = -0.054495066;
        }
    }
    else
    {
        var211 = -0.05572453;
    }
    double var212;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var212 = -0.00725296;
            }
            else
            {
                var212 = 0.040875982;
            }
        }
        else
        {
            var212 = -0.05399418;
        }
    }
    else
    {
        var212 = -0.05532343;
    }
    double var213;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 27.83)
            {
                var213 = 0.016587561;
            }
            else
            {
                var213 = 0.066002995;
            }
        }
        else
        {
            var213 = -0.053528722;
        }
    }
    else
    {
        var213 = -0.05495129;
    }
    double var214;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var214 = -0.0064448416;
            }
            else
            {
                var214 = 0.036183294;
            }
        }
        else
        {
            var214 = -0.05309404;
        }
    }
    else
    {
        var214 = -0.05460752;
    }
    double var215;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.285)
            {
                var215 = 0.038013514;
            }
            else
            {
                var215 = -0.0016864178;
            }
        }
        else
        {
            var215 = -0.052687507;
        }
    }
    else
    {
        var215 = -0.054289825;
    }
    double var216;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.285)
            {
                var216 = 0.03558471;
            }
            else
            {
                var216 = -0.0016652545;
            }
        }
        else
        {
            var216 = -0.05230617;
        }
    }
    else
    {
        var216 = -0.05399672;
    }
    double var217;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var217 = -0.0071944403;
            }
            else
            {
                var217 = 0.03127731;
            }
        }
        else
        {
            var217 = -0.051946487;
        }
    }
    else
    {
        var217 = -0.053724404;
    }
    double var218;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 30.564999)
            {
                var218 = 0.08039191;
            }
            else
            {
                var218 = 0.015104932;
            }
        }
        else
        {
            var218 = -0.05160589;
        }
    }
    else
    {
        var218 = -0.053472847;
    }
    double var219;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var219 = -0.008011359;
            }
            else
            {
                var219 = 0.029165117;
            }
        }
        else
        {
            var219 = -0.05128122;
        }
    }
    else
    {
        var219 = -0.05323715;
    }
    double var220;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 235.0)
            {
                var220 = -0.003954586;
            }
            else
            {
                var220 = -0.05218565;
            }
        }
        else
        {
            if (input[42] >= 28.285)
            {
                var220 = 0.030203855;
            }
            else
            {
                var220 = -0.0045006424;
            }
        }
    }
    else
    {
        var220 = -0.053018298;
    }
    double var221;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 235.0)
            {
                var221 = -0.0033034463;
            }
            else
            {
                var221 = -0.051914375;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var221 = -0.008738617;
            }
            else
            {
                var221 = 0.027612094;
            }
        }
    }
    else
    {
        var221 = -0.052811243;
    }
    double var222;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 235.0)
            {
                var222 = -0.0029168564;
            }
            else
            {
                var222 = -0.05162552;
            }
        }
        else
        {
            if (input[42] >= 30.564999)
            {
                var222 = 0.072325625;
            }
            else
            {
                var222 = 0.011957507;
            }
        }
    }
    else
    {
        var222 = -0.052618157;
    }
    double var223;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var223 = -0.009382169;
            }
            else
            {
                var223 = 0.025963355;
            }
        }
        else
        {
            var223 = -0.050116975;
        }
    }
    else
    {
        var223 = -0.052439094;
    }
    double var224;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 235.0)
            {
                var224 = -0.0016956835;
            }
            else
            {
                var224 = -0.05118559;
            }
        }
        else
        {
            if (input[42] >= 28.869999)
            {
                var224 = -0.0009784016;
            }
            else
            {
                var224 = 0.030490829;
            }
        }
    }
    else
    {
        var224 = -0.05226803;
    }
    double var225;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 235.0)
            {
                var225 = -0.0014184457;
            }
            else
            {
                var225 = -0.050894614;
            }
        }
        else
        {
            if (input[42] >= 30.564999)
            {
                var225 = 0.067720264;
            }
            else
            {
                var225 = 0.010275839;
            }
        }
    }
    else
    {
        var225 = -0.05210904;
    }
    double var226;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.869999)
            {
                var226 = -0.0016516121;
            }
            else
            {
                var226 = 0.02918621;
            }
        }
        else
        {
            var226 = -0.04929694;
        }
    }
    else
    {
        var226 = -0.05195744;
    }
    double var227;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var227 = -0.009796664;
            }
            else
            {
                var227 = 0.023355879;
            }
        }
        else
        {
            var227 = -0.049015578;
        }
    }
    else
    {
        var227 = -0.051812362;
    }
    double var228;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var228 = -0.0016900542;
            }
            else
            {
                var228 = 0.07802114;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var228 = -0.058260687;
            }
            else
            {
                var228 = -0.010430607;
            }
        }
    }
    else
    {
        var228 = -0.0516769;
    }
    double var229;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 30.564999)
            {
                var229 = 0.063218325;
            }
            else
            {
                var229 = 0.008559308;
            }
        }
        else
        {
            var229 = -0.048556175;
        }
    }
    else
    {
        var229 = -0.051549423;
    }
    double var230;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.869999)
            {
                var230 = -0.0023304578;
            }
            else
            {
                var230 = 0.028246317;
            }
        }
        else
        {
            var230 = -0.048258226;
        }
    }
    else
    {
        var230 = -0.051425453;
    }
    double var231;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 226.5)
            {
                var231 = -0.0002948892;
            }
            else
            {
                var231 = -0.0495868;
            }
        }
        else
        {
            if (input[42] >= 28.869999)
            {
                var231 = -0.0022117128;
            }
            else
            {
                var231 = 0.028039059;
            }
        }
    }
    else
    {
        var231 = -0.051309507;
    }
    double var232;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var232 = -0.0021156906;
            }
            else
            {
                var232 = 0.07236188;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var232 = -0.056183573;
            }
            else
            {
                var232 = -0.006728814;
            }
        }
    }
    else
    {
        var232 = -0.051197972;
    }
    double var233;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 30.564999)
            {
                var233 = 0.058824;
            }
            else
            {
                var233 = 0.007053457;
            }
        }
        else
        {
            var233 = -0.047478776;
        }
    }
    else
    {
        var233 = -0.05109166;
    }
    double var234;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var234 = -0.011145094;
            }
            else
            {
                var234 = 0.021623315;
            }
        }
        else
        {
            var234 = -0.047141977;
        }
    }
    else
    {
        var234 = -0.050989505;
    }
    double var235;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.869999)
            {
                var235 = -0.0029765498;
            }
            else
            {
                var235 = 0.02684988;
            }
        }
        else
        {
            var235 = -0.046789046;
        }
    }
    else
    {
        var235 = -0.050891228;
    }
    double var236;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 30.564999)
            {
                var236 = 0.05564764;
            }
            else
            {
                var236 = 0.005675583;
            }
        }
        else
        {
            var236 = -0.046419792;
        }
    }
    else
    {
        var236 = -0.050796326;
    }
    double var237;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.869999)
            {
                var237 = -0.0035760954;
            }
            else
            {
                var237 = 0.026453549;
            }
        }
        else
        {
            var237 = -0.046031486;
        }
    }
    else
    {
        var237 = -0.050704498;
    }
    double var238;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var238 = -0.0033727344;
            }
            else
            {
                var238 = 0.0669738;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var238 = -0.053511776;
            }
            else
            {
                var238 = -0.0017309039;
            }
        }
    }
    else
    {
        var238 = -0.05061543;
    }
    double var239;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var239 = -0.011361039;
            }
            else
            {
                var239 = 0.020122746;
            }
        }
        else
        {
            var239 = -0.04540845;
        }
    }
    else
    {
        var239 = -0.050528765;
    }
    double var240;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 28.869999)
            {
                var240 = -0.0034182933;
            }
            else
            {
                var240 = 0.026032588;
            }
        }
        else
        {
            var240 = -0.044970203;
        }
    }
    else
    {
        var240 = -0.050444074;
    }
    double var241;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 30.564999)
        {
            if (input[56] >= 69.5)
            {
                var241 = -0.043750253;
            }
            else
            {
                var241 = 0.07999976;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var241 = -0.03616057;
            }
            else
            {
                var241 = 0.011254174;
            }
        }
    }
    else
    {
        var241 = -0.050361197;
    }
    double var242;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var242 = -0.0032575221;
            }
            else
            {
                var242 = 0.06385273;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var242 = -0.051664084;
            }
            else
            {
                var242 = -0.00030012502;
            }
        }
    }
    else
    {
        var242 = -0.050279893;
    }
    double var243;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 30.564999)
        {
            if (input[56] >= 69.5)
            {
                var243 = -0.042829197;
            }
            else
            {
                var243 = 0.076882474;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var243 = -0.035087664;
            }
            else
            {
                var243 = 0.01129055;
            }
        }
    }
    else
    {
        var243 = -0.050199892;
    }
    double var244;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[42] >= 29.79)
            {
                var244 = -0.010208148;
            }
            else
            {
                var244 = 0.018439604;
            }
        }
        else
        {
            var244 = -0.043934748;
        }
    }
    else
    {
        var244 = -0.050119508;
    }
    double var245;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var245 = -0.0023258682;
            }
            else
            {
                var245 = 0.06080227;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var245 = -0.051002037;
            }
            else
            {
                var245 = 0.0009355536;
            }
        }
    }
    else
    {
        var245 = -0.05004108;
    }
    double var246;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 30.564999)
        {
            if (input[56] >= 69.5)
            {
                var246 = -0.040801786;
            }
            else
            {
                var246 = 0.07263464;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var246 = -0.033035528;
            }
            else
            {
                var246 = 0.010704075;
            }
        }
    }
    else
    {
        var246 = -0.049962353;
    }
    double var247;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var247 = -0.05345864;
            }
            else
            {
                var247 = 0.0065256744;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var247 = -0.023115393;
            }
            else
            {
                var247 = 0.09457311;
            }
        }
    }
    else
    {
        var247 = -0.0498845;
    }
    double var248;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var248 = -0.052870598;
            }
            else
            {
                var248 = 0.0065550455;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var248 = -0.02237921;
            }
            else
            {
                var248 = 0.090871595;
            }
        }
    }
    else
    {
        var248 = -0.049806815;
    }
    double var249;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var249 = -0.024705572;
            }
            else
            {
                var249 = 0.037993435;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var249 = -0.020974;
            }
            else
            {
                var249 = 0.0365493;
            }
        }
    }
    else
    {
        var249 = -0.049729206;
    }
    double var250;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 27.415)
        {
            if (input[7] >= 1.9494629)
            {
                var250 = -0.0061753923;
            }
            else
            {
                var250 = 0.019845866;
            }
        }
        else
        {
            var250 = -0.04224603;
        }
    }
    else
    {
        var250 = -0.04965175;
    }
    double var251;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var251 = -0.051968474;
            }
            else
            {
                var251 = 0.006597768;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var251 = -0.021718293;
            }
            else
            {
                var251 = 0.085703045;
            }
        }
    }
    else
    {
        var251 = -0.04957382;
    }
    double var252;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var252 = -0.0021659962;
            }
            else
            {
                var252 = 0.057108976;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var252 = -0.049491037;
            }
            else
            {
                var252 = 0.0035494776;
            }
        }
    }
    else
    {
        var252 = -0.049494546;
    }
    double var253;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var253 = -0.051206607;
            }
            else
            {
                var253 = 0.0062212935;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var253 = -0.02038685;
            }
            else
            {
                var253 = 0.08177205;
            }
        }
    }
    else
    {
        var253 = -0.04941495;
    }
    double var254;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var254 = -0.023118498;
            }
            else
            {
                var254 = 0.033966612;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var254 = -0.019353697;
            }
            else
            {
                var254 = 0.034156106;
            }
        }
    }
    else
    {
        var254 = -0.049333643;
    }
    double var255;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var255 = -0.021901552;
            }
            else
            {
                var255 = 0.0322161;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var255 = -0.01877785;
            }
            else
            {
                var255 = 0.032890704;
            }
        }
    }
    else
    {
        var255 = -0.049250443;
    }
    double var256;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var256 = -0.050130617;
            }
            else
            {
                var256 = 0.0058099353;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var256 = -0.01988227;
            }
            else
            {
                var256 = 0.07818627;
            }
        }
    }
    else
    {
        var256 = -0.049167152;
    }
    double var257;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var257 = -0.020702519;
            }
            else
            {
                var257 = 0.0298199;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var257 = -0.01740371;
            }
            else
            {
                var257 = 0.03128638;
            }
        }
    }
    else
    {
        var257 = -0.049081314;
    }
    double var258;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var258 = -0.01554957;
            }
            else
            {
                var258 = 0.01915577;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var258 = 0.04241649;
            }
            else
            {
                var258 = -0.050953932;
            }
        }
    }
    else
    {
        var258 = -0.048994225;
    }
    double var259;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var259 = -0.049177673;
            }
            else
            {
                var259 = 0.005346766;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var259 = -0.018952845;
            }
            else
            {
                var259 = 0.07534335;
            }
        }
    }
    else
    {
        var259 = -0.04890446;
    }
    double var260;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var260 = -0.014662719;
            }
            else
            {
                var260 = 0.018148802;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var260 = 0.039578583;
            }
            else
            {
                var260 = -0.049870986;
            }
        }
    }
    else
    {
        var260 = -0.048812743;
    }
    double var261;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var261 = -0.048562173;
            }
            else
            {
                var261 = 0.0051409057;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var261 = -0.018180827;
            }
            else
            {
                var261 = 0.073663;
            }
        }
    }
    else
    {
        var261 = -0.04871891;
    }
    double var262;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var262 = -0.014267844;
            }
            else
            {
                var262 = 0.017928395;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var262 = 0.03762704;
            }
            else
            {
                var262 = -0.048798855;
            }
        }
    }
    else
    {
        var262 = -0.04862165;
    }
    double var263;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var263 = -0.020039206;
            }
            else
            {
                var263 = 0.027010608;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var263 = -0.014572925;
            }
            else
            {
                var263 = 0.028756117;
            }
        }
    }
    else
    {
        var263 = -0.04852256;
    }
    double var264;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[0] >= 7.709961)
            {
                var264 = -0.025165921;
            }
            else
            {
                var264 = 0.0118657695;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var264 = -0.017716024;
            }
            else
            {
                var264 = 0.07223945;
            }
        }
    }
    else
    {
        var264 = -0.04842138;
    }
    double var265;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var265 = -0.014296536;
            }
            else
            {
                var265 = 0.01731666;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var265 = 0.035228427;
            }
            else
            {
                var265 = -0.047139358;
            }
        }
    }
    else
    {
        var265 = -0.048316177;
    }
    double var266;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var266 = -0.013298045;
            }
            else
            {
                var266 = 0.016254669;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var266 = 0.03410752;
            }
            else
            {
                var266 = -0.045955986;
            }
        }
    }
    else
    {
        var266 = -0.048207447;
    }
    double var267;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var267 = -0.04715242;
            }
            else
            {
                var267 = 0.00426834;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var267 = -0.016534068;
            }
            else
            {
                var267 = 0.07018738;
            }
        }
    }
    else
    {
        var267 = -0.048095316;
    }
    double var268;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var268 = -0.018578418;
            }
            else
            {
                var268 = 0.023945404;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var268 = -0.013396385;
            }
            else
            {
                var268 = 0.026794253;
            }
        }
    }
    else
    {
        var268 = -0.047980037;
    }
    double var269;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var269 = -0.0016264793;
            }
            else
            {
                var269 = 0.052355807;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var269 = -0.048286032;
            }
            else
            {
                var269 = 0.006492392;
            }
        }
    }
    else
    {
        var269 = -0.04786039;
    }
    double var270;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var270 = -0.017778013;
            }
            else
            {
                var270 = 0.023059053;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var270 = -0.012454895;
            }
            else
            {
                var270 = 0.02583089;
            }
        }
    }
    else
    {
        var270 = -0.047736537;
    }
    double var271;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var271 = -0.0015328297;
            }
            else
            {
                var271 = 0.051665056;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var271 = -0.047950804;
            }
            else
            {
                var271 = 0.0070654564;
            }
        }
    }
    else
    {
        var271 = -0.047609195;
    }
    double var272;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var272 = -0.04612839;
            }
            else
            {
                var272 = 0.0041697565;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var272 = -0.01700919;
            }
            else
            {
                var272 = 0.06848889;
            }
        }
    }
    else
    {
        var272 = -0.0474787;
    }
    double var273;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 17.0)
        {
            if (input[42] >= 28.285)
            {
                var273 = 0.014779014;
            }
            else
            {
                var273 = -0.013301729;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var273 = 0.030041074;
            }
            else
            {
                var273 = -0.046320807;
            }
        }
    }
    else
    {
        var273 = -0.04734363;
    }
    double var274;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var274 = -0.017096741;
            }
            else
            {
                var274 = 0.020791838;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var274 = -0.012404355;
            }
            else
            {
                var274 = 0.025418354;
            }
        }
    }
    else
    {
        var274 = -0.047202684;
    }
    double var275;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 17.0)
        {
            if (input[42] >= 29.79)
            {
                var275 = -0.012132368;
            }
            else
            {
                var275 = 0.014675537;
            }
        }
        else
        {
            if (input[42] >= 30.09)
            {
                var275 = 0.029090641;
            }
            else
            {
                var275 = -0.045236625;
            }
        }
    }
    else
    {
        var275 = -0.047058724;
    }
    double var276;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[49] >= 96418.69)
            {
                var276 = -0.016306376;
            }
            else
            {
                var276 = 0.019648543;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var276 = -0.0110348435;
            }
            else
            {
                var276 = 0.023913717;
            }
        }
    }
    else
    {
        var276 = -0.046907943;
    }
    double var277;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 62.5)
        {
            if (input[42] >= 29.79)
            {
                var277 = -0.01206893;
            }
            else
            {
                var277 = 0.014523953;
            }
        }
        else
        {
            if (input[28] >= 4.0992365)
            {
                var277 = -0.03534953;
            }
            else
            {
                var277 = 0.009408504;
            }
        }
    }
    else
    {
        var277 = -0.04675276;
    }
    double var278;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96529.19)
        {
            if (input[42] >= 28.869999)
            {
                var278 = -0.032893024;
            }
            else
            {
                var278 = 0.01011604;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var278 = -0.007371702;
            }
            else
            {
                var278 = 0.066826954;
            }
        }
    }
    else
    {
        var278 = -0.04659183;
    }
    double var279;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var279 = -0.0015553593;
            }
            else
            {
                var279 = 0.050011814;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var279 = -0.04677486;
            }
            else
            {
                var279 = 0.0070738266;
            }
        }
    }
    else
    {
        var279 = -0.04642385;
    }
    double var280;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var280 = -0.044708785;
            }
            else
            {
                var280 = 0.0036861666;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var280 = -0.017306728;
            }
            else
            {
                var280 = 0.06561269;
            }
        }
    }
    else
    {
        var280 = -0.046251107;
    }
    double var281;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96529.19)
        {
            if (input[42] >= 28.869999)
            {
                var281 = -0.031149993;
            }
            else
            {
                var281 = 0.009963108;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var281 = -0.007861865;
            }
            else
            {
                var281 = 0.06499208;
            }
        }
    }
    else
    {
        var281 = -0.046074018;
    }
    double var282;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var282 = -0.044208515;
            }
            else
            {
                var282 = 0.003692988;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var282 = -0.01735255;
            }
            else
            {
                var282 = 0.06442257;
            }
        }
    }
    else
    {
        var282 = -0.045888625;
    }
    double var283;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[28] >= 2.664122)
            {
                var283 = -0.012506636;
            }
            else
            {
                var283 = 0.038077008;
            }
        }
        else
        {
            if (input[56] >= 72.5)
            {
                var283 = -0.004433992;
            }
            else
            {
                var283 = 0.027893651;
            }
        }
    }
    else
    {
        var283 = -0.045699425;
    }
    double var284;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96529.19)
        {
            if (input[42] >= 28.869999)
            {
                var284 = -0.029557684;
            }
            else
            {
                var284 = 0.009190033;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var284 = -0.007954932;
            }
            else
            {
                var284 = 0.06371454;
            }
        }
    }
    else
    {
        var284 = -0.045503523;
    }
    double var285;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var285 = -0.000876049;
            }
            else
            {
                var285 = 0.048208654;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var285 = -0.04511359;
            }
            else
            {
                var285 = 0.005386083;
            }
        }
    }
    else
    {
        var285 = -0.045303434;
    }
    double var286;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var286 = -0.0008926768;
            }
            else
            {
                var286 = 0.047850158;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var286 = -0.044460624;
            }
            else
            {
                var286 = 0.004848296;
            }
        }
    }
    else
    {
        var286 = -0.045096006;
    }
    double var287;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96535.55)
        {
            if (input[42] >= 28.869999)
            {
                var287 = -0.035883732;
            }
            else
            {
                var287 = 0.008361687;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var287 = -0.007946743;
            }
            else
            {
                var287 = 0.048642725;
            }
        }
    }
    else
    {
        var287 = -0.04488208;
    }
    double var288;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 1.9494629)
        {
            if (input[28] >= 2.664122)
            {
                var288 = -0.012200349;
            }
            else
            {
                var288 = 0.037341062;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var288 = -0.010378654;
            }
            else
            {
                var288 = 0.023051929;
            }
        }
    }
    else
    {
        var288 = -0.044660974;
    }
    double var289;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 63.5)
        {
            if (input[42] >= 29.79)
            {
                var289 = -0.011256303;
            }
            else
            {
                var289 = 0.014243391;
            }
        }
        else
        {
            if (input[49] >= 96533.0)
            {
                var289 = -0.03198944;
            }
            else
            {
                var289 = 0.00064531405;
            }
        }
    }
    else
    {
        var289 = -0.04443514;
    }
    double var290;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96535.55)
        {
            if (input[42] >= 28.869999)
            {
                var290 = -0.03457938;
            }
            else
            {
                var290 = 0.007901787;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var290 = -0.00740603;
            }
            else
            {
                var290 = 0.046304088;
            }
        }
    }
    else
    {
        var290 = -0.044202045;
    }
    double var291;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96529.19)
        {
            if (input[0] >= 7.709961)
            {
                var291 = -0.022512358;
            }
            else
            {
                var291 = 0.012055441;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var291 = -0.0068092877;
            }
            else
            {
                var291 = 0.059387147;
            }
        }
    }
    else
    {
        var291 = -0.043962434;
    }
    double var292;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var292 = -0.042603236;
            }
            else
            {
                var292 = 0.0035637468;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var292 = -0.018307721;
            }
            else
            {
                var292 = 0.061229028;
            }
        }
    }
    else
    {
        var292 = -0.043716453;
    }
    double var293;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 63.5)
        {
            if (input[42] >= 29.79)
            {
                var293 = -0.010344364;
            }
            else
            {
                var293 = 0.013700971;
            }
        }
        else
        {
            if (input[49] >= 96533.0)
            {
                var293 = -0.030975252;
            }
            else
            {
                var293 = 0.00010099708;
            }
        }
    }
    else
    {
        var293 = -0.04346338;
    }
    double var294;
    if (input[49] >= 96282.8)
    {
        if (input[42] >= 28.285)
        {
            if (input[42] >= 28.869999)
            {
                var294 = -0.00033859248;
            }
            else
            {
                var294 = 0.046069827;
            }
        }
        else
        {
            if (input[42] >= 27.83)
            {
                var294 = -0.04301645;
            }
            else
            {
                var294 = 0.0039800354;
            }
        }
    }
    else
    {
        var294 = -0.043202378;
    }
    double var295;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96529.19)
        {
            if (input[0] >= 7.6657715)
            {
                var295 = -0.019915832;
            }
            else
            {
                var295 = 0.013541075;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var295 = -0.006630263;
            }
            else
            {
                var295 = 0.057914864;
            }
        }
    }
    else
    {
        var295 = -0.042936742;
    }
    double var296;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96529.19)
        {
            if (input[0] >= 7.6657715)
            {
                var296 = -0.019145103;
            }
            else
            {
                var296 = 0.012871887;
            }
        }
        else
        {
            if (input[42] >= 29.79)
            {
                var296 = -0.0066454983;
            }
            else
            {
                var296 = 0.05689329;
            }
        }
    }
    else
    {
        var296 = -0.04266269;
    }
    double var297;
    if (input[49] >= 96282.8)
    {
        if (input[49] >= 96416.15)
        {
            if (input[42] >= 29.795)
            {
                var297 = -0.041439075;
            }
            else
            {
                var297 = 0.0027802926;
            }
        }
        else
        {
            if (input[56] >= 69.5)
            {
                var297 = -0.017925179;
            }
            else
            {
                var297 = 0.05940888;
            }
        }
    }
    else
    {
        var297 = -0.04238549;
    }
    double var298;
    if (input[42] >= 28.355)
    {
        if (input[49] >= 96626.99)
        {
            var298 = 0.043934755;
        }
        else
        {
            if (input[42] >= 29.225)
            {
                var298 = 0.011181033;
            }
            else
            {
                var298 = -0.03595041;
            }
        }
    }
    else
    {
        if (input[49] >= 96779.42)
        {
            if (input[42] >= 27.435001)
            {
                var298 = 0.02176461;
            }
            else
            {
                var298 = -0.024426518;
            }
        }
        else
        {
            var298 = -0.04451788;
        }
    }
    double var299;
    if (input[49] >= 96282.8)
    {
        if (input[56] >= 17.0)
        {
            if (input[42] >= 28.285)
            {
                var299 = 0.012193738;
            }
            else
            {
                var299 = -0.012563477;
            }
        }
        else
        {
            if (input[49] >= 96533.0)
            {
                var299 = -0.03522071;
            }
            else
            {
                var299 = -0.0015707966;
            }
        }
    }
    else
    {
        var299 = -0.041795503;
    }
    double var300;
    if (input[49] >= 96282.8)
    {
        if (input[7] >= 2.0393066)
        {
            if (input[35] >= 482.93893)
            {
                var300 = 0.008723033;
            }
            else
            {
                var300 = -0.040439613;
            }
        }
        else
        {
            if (input[35] >= 496.39694)
            {
                var300 = -0.009662164;
            }
            else
            {
                var300 = 0.01342544;
            }
        }
    }
    else
    {
        var300 = -0.041498095;
    }
    double var301;
    if (input[49] >= 96149.445)
    {
        var301 = -0.062272128;
    }
    else
    {
        if (input[42] >= 28.485)
        {
            if (input[56] >= 111.5)
            {
                var301 = -0.060549315;
            }
            else
            {
                var301 = 0.009485095;
            }
        }
        else
        {
            if (input[28] >= 232.2939)
            {
                var301 = 0.1274928;
            }
            else
            {
                var301 = 0.06328881;
            }
        }
    }
    double var302;
    if (input[49] >= 96149.445)
    {
        var302 = -0.061273646;
    }
    else
    {
        if (input[42] >= 28.39)
        {
            if (input[56] >= 111.5)
            {
                var302 = -0.05608922;
            }
            else
            {
                var302 = 0.051739093;
            }
        }
        else
        {
            if (input[28] >= 232.2939)
            {
                var302 = 0.112130105;
            }
            else
            {
                var302 = 0.057058502;
            }
        }
    }
    double var303;
    if (input[49] >= 96149.445)
    {
        var303 = -0.060362894;
    }
    else
    {
        if (input[42] >= 28.485)
        {
            if (input[56] >= 111.5)
            {
                var303 = -0.05875067;
            }
            else
            {
                var303 = 0.00863479;
            }
        }
        else
        {
            if (input[28] >= 232.2939)
            {
                var303 = 0.09484883;
            }
            else
            {
                var303 = 0.051676095;
            }
        }
    }
    double var304;
    if (input[49] >= 96149.445)
    {
        var304 = -0.059511643;
    }
    else
    {
        if (input[42] >= 28.485)
        {
            if (input[56] >= 111.5)
            {
                var304 = -0.057913583;
            }
            else
            {
                var304 = 0.009259542;
            }
        }
        else
        {
            if (input[28] >= 232.2939)
            {
                var304 = 0.083656006;
            }
            else
            {
                var304 = 0.04707183;
            }
        }
    }
    double var305;
    if (input[49] >= 96149.445)
    {
        var305 = -0.05872484;
    }
    else
    {
        if (input[42] >= 28.39)
        {
            if (input[56] >= 111.5)
            {
                var305 = -0.05478534;
            }
            else
            {
                var305 = 0.043825686;
            }
        }
        else
        {
            if (input[7] >= 3.05542)
            {
                var305 = -0.002988597;
            }
            else
            {
                var305 = 0.066707075;
            }
        }
    }
    double var306;
    if (input[49] >= 96149.445)
    {
        var306 = -0.05799183;
    }
    else
    {
        if (input[42] >= 28.485)
        {
            if (input[56] >= 111.5)
            {
                var306 = -0.056423422;
            }
            else
            {
                var306 = 0.008591515;
            }
        }
        else
        {
            if (input[7] >= 1.3818359)
            {
                var306 = 0.060707737;
            }
            else
            {
                var306 = 0.012914687;
            }
        }
    }
    double var307;
    if (input[49] >= 96149.445)
    {
        var307 = -0.05732596;
    }
    else
    {
        if (input[49] >= 94681.74)
        {
            if (input[7] >= 3.05542)
            {
                var307 = -0.0071614766;
            }
            else
            {
                var307 = 0.05449329;
            }
        }
        else
        {
            if (input[56] >= 101.0)
            {
                var307 = -0.052400142;
            }
            else
            {
                var307 = 0.03545802;
            }
        }
    }
    double var308;
    if (input[49] >= 96149.445)
    {
        var308 = -0.056704696;
    }
    else
    {
        if (input[42] >= 28.485)
        {
            if (input[56] >= 111.5)
            {
                var308 = -0.055188805;
            }
            else
            {
                var308 = 0.008919695;
            }
        }
        else
        {
            if (input[7] >= 1.2424316)
            {
                var308 = 0.04975728;
            }
            else
            {
                var308 = -0.003232592;
            }
        }
    }
    double var309;
    if (input[49] >= 96149.445)
    {
        var309 = -0.056141853;
    }
    else
    {
        if (input[42] >= 28.39)
        {
            if (input[56] >= 114.5)
            {
                var309 = -0.05601285;
            }
            else
            {
                var309 = 0.033657845;
            }
        }
        else
        {
            if (input[7] >= 3.05542)
            {
                var309 = -0.010454996;
            }
            else
            {
                var309 = 0.04680228;
            }
        }
    }
    double var310;
    if (input[49] >= 96149.445)
    {
        var310 = -0.055614363;
    }
    else
    {
        if (input[7] >= 1.3901367)
        {
            if (input[28] >= 356.90076)
            {
                var310 = 0.05405373;
            }
            else
            {
                var310 = 0.026362125;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var310 = -0.030055935;
            }
            else
            {
                var310 = 0.03762457;
            }
        }
    }
    double var311;
    if (input[49] >= 96149.445)
    {
        var311 = -0.055138845;
    }
    else
    {
        if (input[7] >= 1.2424316)
        {
            if (input[7] >= 3.05542)
            {
                var311 = -0.011574878;
            }
            else
            {
                var311 = 0.04040463;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var311 = -0.040024534;
            }
            else
            {
                var311 = 0.025309741;
            }
        }
    }
    double var312;
    if (input[49] >= 96149.445)
    {
        var312 = -0.05469463;
    }
    else
    {
        if (input[49] >= 94681.74)
        {
            if (input[7] >= 3.05542)
            {
                var312 = -0.011535091;
            }
            else
            {
                var312 = 0.036836922;
            }
        }
        else
        {
            if (input[56] >= 101.0)
            {
                var312 = -0.051523995;
            }
            else
            {
                var312 = 0.030074323;
            }
        }
    }
    double var313;
    if (input[49] >= 96149.445)
    {
        var313 = -0.05428822;
    }
    else
    {
        if (input[7] >= 1.3901367)
        {
            if (input[28] >= 356.90076)
            {
                var313 = 0.044390645;
            }
            else
            {
                var313 = 0.020235877;
            }
        }
        else
        {
            if (input[21] >= 470.59924)
            {
                var313 = -0.03300216;
            }
            else
            {
                var313 = 0.028613565;
            }
        }
    }
    double var314;
    if (input[49] >= 96149.445)
    {
        var314 = -0.053911515;
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var314 = -0.053587865;
            }
            else
            {
                var314 = 0.022837795;
            }
        }
        else
        {
            if (input[42] >= 24.965)
            {
                var314 = 0.03476676;
            }
            else
            {
                var314 = 0.10794776;
            }
        }
    }
    double var315;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var315 = -0.0620658;
            }
            else
            {
                var315 = -0.03179601;
            }
        }
        else
        {
            if (input[49] >= 96148.18)
            {
                var315 = -0.05024263;
            }
            else
            {
                var315 = 0.06738091;
            }
        }
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var315 = -0.052703053;
            }
            else
            {
                var315 = 0.022091432;
            }
        }
        else
        {
            if (input[42] >= 25.235)
            {
                var315 = 0.037584193;
            }
            else
            {
                var315 = 0.0917838;
            }
        }
    }
    double var316;
    if (input[49] >= 96149.445)
    {
        var316 = -0.053277887;
    }
    else
    {
        if (input[7] >= 1.2424316)
        {
            if (input[7] >= 3.05542)
            {
                var316 = -0.013677281;
            }
            else
            {
                var316 = 0.029102743;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var316 = -0.040493805;
            }
            else
            {
                var316 = 0.018281708;
            }
        }
    }
    double var317;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var317 = -0.062165823;
            }
            else
            {
                var317 = -0.029373525;
            }
        }
        else
        {
            if (input[49] >= 96148.18)
            {
                var317 = -0.049150575;
            }
            else
            {
                var317 = 0.061654758;
            }
        }
    }
    else
    {
        if (input[56] >= 118.5)
        {
            if (input[42] >= 28.385)
            {
                var317 = -0.05502642;
            }
            else
            {
                var317 = 0.017300738;
            }
        }
        else
        {
            if (input[42] >= 25.275002)
            {
                var317 = 0.029054997;
            }
            else
            {
                var317 = 0.07070857;
            }
        }
    }
    double var318;
    if (input[49] >= 96149.445)
    {
        var318 = -0.052721243;
    }
    else
    {
        if (input[7] >= 1.2424316)
        {
            if (input[7] >= 2.8327637)
            {
                var318 = -0.005534561;
            }
            else
            {
                var318 = 0.026652088;
            }
        }
        else
        {
            if (input[21] >= 462.34732)
            {
                var318 = -0.036499497;
            }
            else
            {
                var318 = 0.020373056;
            }
        }
    }
    double var319;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var319 = -0.06231122;
            }
            else
            {
                var319 = -0.02689381;
            }
        }
        else
        {
            if (input[49] >= 96148.18)
            {
                var319 = -0.04806778;
            }
            else
            {
                var319 = 0.0567408;
            }
        }
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var319 = -0.051660426;
            }
            else
            {
                var319 = 0.016493274;
            }
        }
        else
        {
            if (input[49] >= 95755.78)
            {
                var319 = 0.05214683;
            }
            else
            {
                var319 = 0.0190123;
            }
        }
    }
    double var320;
    if (input[49] >= 96149.445)
    {
        var320 = -0.052237656;
    }
    else
    {
        if (input[7] >= 1.3901367)
        {
            if (input[28] >= 356.90076)
            {
                var320 = 0.030816553;
            }
            else
            {
                var320 = 0.011044928;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var320 = -0.031819705;
            }
            else
            {
                var320 = 0.02222178;
            }
        }
    }
    double var321;
    if (input[49] >= 96149.445)
    {
        var321 = -0.051997896;
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var321 = -0.050998803;
            }
            else
            {
                var321 = 0.013614093;
            }
        }
        else
        {
            if (input[42] >= 24.965)
            {
                var321 = 0.022863563;
            }
            else
            {
                var321 = 0.08325758;
            }
        }
    }
    double var322;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var322 = -0.06270732;
            }
            else
            {
                var322 = -0.022801748;
            }
        }
        else
        {
            if (input[49] >= 96148.18)
            {
                var322 = -0.04639728;
            }
            else
            {
                var322 = 0.048227172;
            }
        }
    }
    else
    {
        if (input[56] >= 118.5)
        {
            if (input[42] >= 26.36)
            {
                var322 = 0.019769337;
            }
            else
            {
                var322 = -0.012110659;
            }
        }
        else
        {
            if (input[42] >= 25.275002)
            {
                var322 = 0.021271665;
            }
            else
            {
                var322 = 0.059749234;
            }
        }
    }
    double var323;
    if (input[49] >= 96149.445)
    {
        var323 = -0.051600214;
    }
    else
    {
        if (input[0] >= 1.9448242)
        {
            if (input[42] >= 25.465)
            {
                var323 = -0.0022391176;
            }
            else
            {
                var323 = 0.03063989;
            }
        }
        else
        {
            if (input[7] >= 2.9455566)
            {
                var323 = -0.016668683;
            }
            else
            {
                var323 = 0.023610305;
            }
        }
    }
    double var324;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var324 = -0.062355917;
            }
            else
            {
                var324 = -0.019989703;
            }
        }
        else
        {
            if (input[49] >= 96148.18)
            {
                var324 = -0.045231942;
            }
            else
            {
                var324 = 0.04403954;
            }
        }
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var324 = -0.05017181;
            }
            else
            {
                var324 = 0.011815712;
            }
        }
        else
        {
            if (input[42] >= 25.205)
            {
                var324 = 0.023059163;
            }
            else
            {
                var324 = 0.07212777;
            }
        }
    }
    double var325;
    if (input[49] >= 96149.445)
    {
        var325 = -0.05123616;
    }
    else
    {
        if (input[35] >= 49.33206)
        {
            if (input[7] >= 1.3088379)
            {
                var325 = 0.023464544;
            }
            else
            {
                var325 = -0.014728486;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var325 = -0.008404016;
            }
            else
            {
                var325 = 0.016870288;
            }
        }
    }
    double var326;
    if (input[49] >= 96149.445)
    {
        var326 = -0.05104178;
    }
    else
    {
        if (input[49] >= 95656.75)
        {
            if (input[28] >= 357.6107)
            {
                var326 = 0.030647889;
            }
            else
            {
                var326 = 0.0034170975;
            }
        }
        else
        {
            if (input[56] >= 92.5)
            {
                var326 = -0.010020428;
            }
            else
            {
                var326 = 0.02801748;
            }
        }
    }
    double var327;
    if (input[49] >= 96149.445)
    {
        var327 = -0.050845172;
    }
    else
    {
        if (input[7] >= 1.2424316)
        {
            if (input[7] >= 2.8327637)
            {
                var327 = -0.009841458;
            }
            else
            {
                var327 = 0.016661821;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var327 = -0.039582152;
            }
            else
            {
                var327 = 0.011442923;
            }
        }
    }
    double var328;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var328 = -0.06272369;
            }
            else
            {
                var328 = -0.013858351;
            }
        }
        else
        {
            if (input[56] >= 110.5)
            {
                var328 = -0.043876894;
            }
            else
            {
                var328 = 0.048304427;
            }
        }
    }
    else
    {
        if (input[35] >= 53.30153)
        {
            if (input[35] >= 407.00763)
            {
                var328 = 0.015097451;
            }
            else
            {
                var328 = 0.050859954;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var328 = -0.008312005;
            }
            else
            {
                var328 = 0.0153222;
            }
        }
    }
    double var329;
    if (input[49] >= 96149.445)
    {
        var329 = -0.050532043;
    }
    else
    {
        if (input[49] >= 95656.75)
        {
            if (input[28] >= 250.13359)
            {
                var329 = 0.026800966;
            }
            else
            {
                var329 = 0.0018578796;
            }
        }
        else
        {
            if (input[56] >= 92.5)
            {
                var329 = -0.010760797;
            }
            else
            {
                var329 = 0.024949415;
            }
        }
    }
    double var330;
    if (input[49] >= 96149.445)
    {
        var330 = -0.05034981;
    }
    else
    {
        if (input[7] >= 1.2424316)
        {
            if (input[7] >= 2.8327637)
            {
                var330 = -0.010187891;
            }
            else
            {
                var330 = 0.014387189;
            }
        }
        else
        {
            if (input[21] >= 467.03436)
            {
                var330 = -0.03860655;
            }
            else
            {
                var330 = 0.01054154;
            }
        }
    }
    double var331;
    if (input[49] >= 96149.445)
    {
        var331 = -0.05016048;
    }
    else
    {
        if (input[35] >= 49.33206)
        {
            if (input[35] >= 127.53435)
            {
                var331 = 0.011571272;
            }
            else
            {
                var331 = 0.041354954;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var331 = -0.009304347;
            }
            else
            {
                var331 = 0.012456135;
            }
        }
    }
    double var332;
    if (input[49] >= 96093.57)
    {
        if (input[42] >= 25.335)
        {
            if (input[28] >= 495.1832)
            {
                var332 = -0.028319567;
            }
            else
            {
                var332 = -0.06287039;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var332 = 0.08466408;
            }
            else
            {
                var332 = -0.012036637;
            }
        }
    }
    else
    {
        if (input[42] >= 25.46)
        {
            if (input[49] >= 96002.13)
            {
                var332 = -0.04584501;
            }
            else
            {
                var332 = 0.010903265;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var332 = -0.009258139;
            }
            else
            {
                var332 = 0.04607303;
            }
        }
    }
    double var333;
    if (input[49] >= 96149.445)
    {
        var333 = -0.049786646;
    }
    else
    {
        if (input[49] >= 95656.75)
        {
            if (input[7] >= 3.0646973)
            {
                var333 = -0.032347575;
            }
            else
            {
                var333 = 0.015673412;
            }
        }
        else
        {
            if (input[42] >= 27.455)
            {
                var333 = 0.009967736;
            }
            else
            {
                var333 = -0.023324294;
            }
        }
    }
    double var334;
    if (input[49] >= 96093.57)
    {
        if (input[42] >= 24.965)
        {
            if (input[42] >= 25.335)
            {
                var334 = -0.056997336;
            }
            else
            {
                var334 = -0.019184096;
            }
        }
        else
        {
            if (input[56] >= 113.5)
            {
                var334 = -0.04212237;
            }
            else
            {
                var334 = 0.047570404;
            }
        }
    }
    else
    {
        if (input[42] >= 25.46)
        {
            if (input[49] >= 96002.13)
            {
                var334 = -0.044468354;
            }
            else
            {
                var334 = 0.009931034;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var334 = -0.009428954;
            }
            else
            {
                var334 = 0.043177497;
            }
        }
    }
    double var335;
    if (input[49] >= 96149.445)
    {
        var335 = -0.049424995;
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var335 = -0.04909211;
            }
            else
            {
                var335 = 0.0046749543;
            }
        }
        else
        {
            if (input[42] >= 24.965)
            {
                var335 = 0.011795777;
            }
            else
            {
                var335 = 0.063931175;
            }
        }
    }
    double var336;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 25.335)
        {
            if (input[28] >= 480.9084)
            {
                var336 = -0.033169072;
            }
            else
            {
                var336 = -0.066506356;
            }
        }
        else
        {
            if (input[56] >= 110.5)
            {
                var336 = -0.03612456;
            }
            else
            {
                var336 = 0.016582806;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 95979.27)
            {
                var336 = -0.03281314;
            }
            else
            {
                var336 = 0.010074029;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var336 = -0.009342745;
            }
            else
            {
                var336 = 0.04748936;
            }
        }
    }
    double var337;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var337 = -0.062594905;
            }
            else
            {
                var337 = 0.0010829562;
            }
        }
        else
        {
            if (input[56] >= 109.5)
            {
                var337 = -0.037491035;
            }
            else
            {
                var337 = 0.0539356;
            }
        }
    }
    else
    {
        if (input[0] >= 6.911133)
        {
            if (input[14] >= 7.748291)
            {
                var337 = -0.021657249;
            }
            else
            {
                var337 = 0.004076757;
            }
        }
        else
        {
            if (input[49] >= 95628.81)
            {
                var337 = 0.017248735;
            }
            else
            {
                var337 = -0.008400513;
            }
        }
    }
    double var338;
    if (input[49] >= 96149.445)
    {
        var338 = -0.048984468;
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 24.79)
            {
                var338 = 0.0032687436;
            }
            else
            {
                var338 = -0.058309834;
            }
        }
        else
        {
            if (input[42] >= 24.945)
            {
                var338 = 0.01141621;
            }
            else
            {
                var338 = 0.06819282;
            }
        }
    }
    double var339;
    if (input[49] >= 96149.445)
    {
        var339 = -0.04877062;
    }
    else
    {
        if (input[35] >= 49.33206)
        {
            if (input[35] >= 127.53435)
            {
                var339 = 0.0077433693;
            }
            else
            {
                var339 = 0.03723825;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var339 = -0.011327478;
            }
            else
            {
                var339 = 0.008899448;
            }
        }
    }
    double var340;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 25.335)
        {
            if (input[28] >= 480.9084)
            {
                var340 = -0.029603953;
            }
            else
            {
                var340 = -0.06638736;
            }
        }
        else
        {
            if (input[56] >= 110.5)
            {
                var340 = -0.034239095;
            }
            else
            {
                var340 = 0.015829938;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 95979.27)
            {
                var340 = -0.03294027;
            }
            else
            {
                var340 = 0.00850557;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var340 = -0.009472116;
            }
            else
            {
                var340 = 0.043867264;
            }
        }
    }
    double var341;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.945)
        {
            if (input[56] >= 77.5)
            {
                var341 = -0.053650856;
            }
            else
            {
                var341 = 0.005836436;
            }
        }
        else
        {
            if (input[49] >= 96149.445)
            {
                var341 = -0.033716418;
            }
            else
            {
                var341 = 0.049614713;
            }
        }
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[7] >= 1.3818359)
            {
                var341 = 0.005072033;
            }
            else
            {
                var341 = -0.028440062;
            }
        }
        else
        {
            if (input[42] >= 25.235)
            {
                var341 = 0.011086359;
            }
            else
            {
                var341 = 0.052759875;
            }
        }
    }
    double var342;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 25.335)
        {
            if (input[28] >= 480.9084)
            {
                var342 = -0.028373335;
            }
            else
            {
                var342 = -0.06579219;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var342 = 0.07974487;
            }
            else
            {
                var342 = -0.008797734;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var342 = 0.005591641;
            }
            else
            {
                var342 = -0.07756273;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var342 = -0.009160718;
            }
            else
            {
                var342 = 0.041540835;
            }
        }
    }
    double var343;
    if (input[49] >= 96149.445)
    {
        var343 = -0.04809759;
    }
    else
    {
        if (input[0] >= 0.018066406)
        {
            if (input[0] >= 6.911133)
            {
                var343 = -0.0033401423;
            }
            else
            {
                var343 = 0.009290754;
            }
        }
        else
        {
            if (input[14] >= 7.914551)
            {
                var343 = 0.020714492;
            }
            else
            {
                var343 = -0.066386595;
            }
        }
    }
    double var344;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 25.145)
        {
            if (input[56] >= 77.5)
            {
                var344 = -0.046086732;
            }
            else
            {
                var344 = 0.004583286;
            }
        }
        else
        {
            if (input[56] >= 113.5)
            {
                var344 = -0.04142673;
            }
            else
            {
                var344 = 0.03502086;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 96002.13)
            {
                var344 = -0.040524207;
            }
            else
            {
                var344 = 0.006501557;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var344 = -0.008589228;
            }
            else
            {
                var344 = 0.039545882;
            }
        }
    }
    double var345;
    if (input[49] >= 96149.445)
    {
        var345 = -0.04779798;
    }
    else
    {
        if (input[28] >= 19.41603)
        {
            if (input[28] >= 232.2939)
            {
                var345 = 0.0077820243;
            }
            else
            {
                var345 = -0.006039045;
            }
        }
        else
        {
            if (input[28] >= 16.706106)
            {
                var345 = 0.06499615;
            }
            else
            {
                var345 = 0.012803026;
            }
        }
    }
    double var346;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.945)
        {
            if (input[56] >= 77.5)
            {
                var346 = -0.05180217;
            }
            else
            {
                var346 = 0.0095020365;
            }
        }
        else
        {
            if (input[56] >= 112.5)
            {
                var346 = -0.017457614;
            }
            else
            {
                var346 = 0.05284807;
            }
        }
    }
    else
    {
        if (input[0] >= 7.2072754)
        {
            if (input[14] >= 7.748291)
            {
                var346 = -0.024444237;
            }
            else
            {
                var346 = 0.002075366;
            }
        }
        else
        {
            if (input[49] >= 95656.75)
            {
                var346 = 0.0140348;
            }
            else
            {
                var346 = -0.0062942016;
            }
        }
    }
    double var347;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 25.335)
        {
            if (input[28] >= 480.9084)
            {
                var347 = -0.024521112;
            }
            else
            {
                var347 = -0.06521831;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var347 = 0.07444866;
            }
            else
            {
                var347 = -0.007970571;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var347 = 0.0044385167;
            }
            else
            {
                var347 = -0.07506847;
            }
        }
        else
        {
            if (input[56] >= 121.5)
            {
                var347 = -0.008541695;
            }
            else
            {
                var347 = 0.037095256;
            }
        }
    }
    double var348;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var348 = -0.02379856;
            }
            else
            {
                var348 = -0.06289502;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var348 = 0.07333437;
            }
            else
            {
                var348 = -0.0046519893;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 95979.27)
            {
                var348 = -0.030512804;
            }
            else
            {
                var348 = 0.006427647;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var348 = -0.0027200389;
            }
            else
            {
                var348 = 0.050017744;
            }
        }
    }
    double var349;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.945)
        {
            if (input[56] >= 77.5)
            {
                var349 = -0.050510805;
            }
            else
            {
                var349 = 0.009739622;
            }
        }
        else
        {
            if (input[56] >= 112.5)
            {
                var349 = -0.016162775;
            }
            else
            {
                var349 = 0.052126974;
            }
        }
    }
    else
    {
        if (input[0] >= 0.015380859)
        {
            if (input[0] >= 7.2072754)
            {
                var349 = -0.0056450306;
            }
            else
            {
                var349 = 0.00916054;
            }
        }
        else
        {
            if (input[14] >= 7.914551)
            {
                var349 = 0.005189016;
            }
            else
            {
                var349 = -0.069800675;
            }
        }
    }
    double var350;
    if (input[49] >= 96149.445)
    {
        var350 = -0.046969797;
    }
    else
    {
        if (input[28] >= 19.41603)
        {
            if (input[56] >= 113.5)
            {
                var350 = -0.003180381;
            }
            else
            {
                var350 = 0.009307102;
            }
        }
        else
        {
            if (input[28] >= 16.706106)
            {
                var350 = 0.058756936;
            }
            else
            {
                var350 = 0.01124424;
            }
        }
    }
    double var351;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var351 = -0.022379896;
            }
            else
            {
                var351 = -0.062132157;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var351 = 0.06834907;
            }
            else
            {
                var351 = -0.0046733744;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var351 = 0.003680699;
            }
            else
            {
                var351 = -0.07225167;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var351 = 0.0621424;
            }
            else
            {
                var351 = 0.0060852747;
            }
        }
    }
    double var352;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var352 = -0.059536185;
            }
            else
            {
                var352 = 0.011112949;
            }
        }
        else
        {
            if (input[7] >= 1.9440918)
            {
                var352 = -0.029186968;
            }
            else
            {
                var352 = 0.057753224;
            }
        }
    }
    else
    {
        if (input[35] >= 53.30153)
        {
            if (input[35] >= 407.00763)
            {
                var352 = 0.004491547;
            }
            else
            {
                var352 = 0.039287098;
            }
        }
        else
        {
            if (input[0] >= 0.29956055)
            {
                var352 = 0.0019805485;
            }
            else
            {
                var352 = -0.020656597;
            }
        }
    }
    double var353;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var353 = -0.021395642;
            }
            else
            {
                var353 = -0.06111992;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var353 = 0.06491539;
            }
            else
            {
                var353 = -0.004278574;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 95979.27)
            {
                var353 = -0.029758727;
            }
            else
            {
                var353 = 0.0053736432;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var353 = -0.0033149444;
            }
            else
            {
                var353 = 0.046476696;
            }
        }
    }
    double var354;
    if (input[0] >= 7.2072754)
    {
        if (input[14] >= 7.748291)
        {
            if (input[35] >= 86.645035)
            {
                var354 = 0.000688544;
            }
            else
            {
                var354 = -0.043499548;
            }
        }
        else
        {
            if (input[0] >= 7.974121)
            {
                var354 = -0.046219956;
            }
            else
            {
                var354 = 0.003987571;
            }
        }
    }
    else
    {
        if (input[0] >= 0.2644043)
        {
            if (input[49] >= 95656.75)
            {
                var354 = 0.014305296;
            }
            else
            {
                var354 = -0.0068184347;
            }
        }
        else
        {
            if (input[21] >= 10.507633)
            {
                var354 = -0.015431525;
            }
            else
            {
                var354 = 0.0154249715;
            }
        }
    }
    double var355;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var355 = -0.020311754;
            }
            else
            {
                var355 = -0.060360253;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var355 = 0.061953273;
            }
            else
            {
                var355 = -0.0049066744;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var355 = 0.0032434908;
            }
            else
            {
                var355 = -0.06948214;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var355 = 0.058776736;
            }
            else
            {
                var355 = 0.0042891973;
            }
        }
    }
    double var356;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var356 = -0.058458537;
            }
            else
            {
                var356 = 0.011572279;
            }
        }
        else
        {
            if (input[56] >= 109.5)
            {
                var356 = -0.032054473;
            }
            else
            {
                var356 = 0.054527044;
            }
        }
    }
    else
    {
        if (input[0] >= 7.2072754)
        {
            if (input[14] >= 7.748291)
            {
                var356 = -0.022271425;
            }
            else
            {
                var356 = 0.00027710194;
            }
        }
        else
        {
            if (input[49] >= 95628.81)
            {
                var356 = 0.010899427;
            }
            else
            {
                var356 = -0.009077658;
            }
        }
    }
    double var357;
    if (input[0] >= 0.018066406)
    {
        if (input[21] >= 487.90457)
        {
            if (input[42] >= 25.46)
            {
                var357 = -0.01272999;
            }
            else
            {
                var357 = 0.01445016;
            }
        }
        else
        {
            if (input[21] >= 28.667938)
            {
                var357 = 0.012032059;
            }
            else
            {
                var357 = -0.0021096293;
            }
        }
    }
    else
    {
        if (input[14] >= 7.914551)
        {
            var357 = 0.01584392;
        }
        else
        {
            if (input[49] >= 96106.266)
            {
                var357 = -0.007244435;
            }
            else
            {
                var357 = -0.0667606;
            }
        }
    }
    double var358;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var358 = -0.019649612;
            }
            else
            {
                var358 = -0.059768368;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var358 = 0.058544338;
            }
            else
            {
                var358 = -0.0055185426;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 96002.13)
            {
                var358 = -0.036866818;
            }
            else
            {
                var358 = 0.0043145115;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var358 = 0.05631646;
            }
            else
            {
                var358 = 0.003829222;
            }
        }
    }
    double var359;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 24.974998)
        {
            if (input[42] >= 25.375)
            {
                var359 = -0.057881594;
            }
            else
            {
                var359 = -0.01772633;
            }
        }
        else
        {
            if (input[56] >= 113.5)
            {
                var359 = -0.036009323;
            }
            else
            {
                var359 = 0.04261842;
            }
        }
    }
    else
    {
        if (input[35] >= 49.33206)
        {
            if (input[35] >= 430.85495)
            {
                var359 = 0.0028631894;
            }
            else
            {
                var359 = 0.031999353;
            }
        }
        else
        {
            if (input[35] >= 42.610687)
            {
                var359 = -0.040189188;
            }
            else
            {
                var359 = -0.0007568551;
            }
        }
    }
    double var360;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.945)
        {
            if (input[56] >= 77.5)
            {
                var360 = -0.047997136;
            }
            else
            {
                var360 = 0.013021137;
            }
        }
        else
        {
            if (input[56] >= 112.5)
            {
                var360 = -0.012139021;
            }
            else
            {
                var360 = 0.048805367;
            }
        }
    }
    else
    {
        if (input[0] >= 7.2072754)
        {
            if (input[14] >= 7.748291)
            {
                var360 = -0.02183014;
            }
            else
            {
                var360 = 0.000028655251;
            }
        }
        else
        {
            if (input[0] >= 0.8823242)
            {
                var360 = 0.019153882;
            }
            else
            {
                var360 = 0.001561548;
            }
        }
    }
    double var361;
    if (input[28] >= 52.24046)
    {
        if (input[28] >= 232.2939)
        {
            if (input[49] >= 95644.05)
            {
                var361 = 0.0108145615;
            }
            else
            {
                var361 = -0.014134253;
            }
        }
        else
        {
            if (input[7] >= 1.5983887)
            {
                var361 = -0.026249273;
            }
            else
            {
                var361 = 0.015096714;
            }
        }
    }
    else
    {
        if (input[14] >= 7.3813477)
        {
            if (input[28] >= 48.62214)
            {
                var361 = 0.056352444;
            }
            else
            {
                var361 = -0.0025965653;
            }
        }
        else
        {
            if (input[7] >= 1.6870117)
            {
                var361 = 0.008974696;
            }
            else
            {
                var361 = 0.04748894;
            }
        }
    }
    double var362;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var362 = -0.01750662;
            }
            else
            {
                var362 = -0.05862202;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var362 = 0.056062635;
            }
            else
            {
                var362 = -0.0054805945;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var362 = 0.002534238;
            }
            else
            {
                var362 = -0.067746855;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var362 = -0.0042665135;
            }
            else
            {
                var362 = 0.041436065;
            }
        }
    }
    double var363;
    if (input[21] >= 487.90457)
    {
        if (input[42] >= 25.46)
        {
            if (input[49] >= 95925.94)
            {
                var363 = -0.06334688;
            }
            else
            {
                var363 = -0.00013837304;
            }
        }
        else
        {
            if (input[42] >= 25.3)
            {
                var363 = 0.049524914;
            }
            else
            {
                var363 = -0.005768923;
            }
        }
    }
    else
    {
        if (input[21] >= 28.667938)
        {
            if (input[0] >= 0.25146484)
            {
                var363 = 0.014368683;
            }
            else
            {
                var363 = -0.012217318;
            }
        }
        else
        {
            if (input[28] >= 53.48855)
            {
                var363 = -0.01268013;
            }
            else
            {
                var363 = 0.016199816;
            }
        }
    }
    double var364;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.335)
        {
            if (input[0] >= 7.772949)
            {
                var364 = -0.016542993;
            }
            else
            {
                var364 = -0.05781969;
            }
        }
        else
        {
            if (input[42] >= 25.314999)
            {
                var364 = 0.05284932;
            }
            else
            {
                var364 = -0.0056597064;
            }
        }
    }
    else
    {
        if (input[0] >= 1.6547852)
        {
            if (input[42] >= 25.490002)
            {
                var364 = -0.00865955;
            }
            else
            {
                var364 = 0.029760769;
            }
        }
        else
        {
            if (input[49] >= 95628.81)
            {
                var364 = 0.01196073;
            }
            else
            {
                var364 = -0.011231888;
            }
        }
    }
    double var365;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.14)
            {
                var365 = -0.0653045;
            }
            else
            {
                var365 = 0.023826698;
            }
        }
        else
        {
            var365 = 0.045040958;
        }
    }
    else
    {
        if (input[49] >= 96078.33)
        {
            if (input[42] >= 25.335)
            {
                var365 = -0.050418247;
            }
            else
            {
                var365 = -0.0013164859;
            }
        }
        else
        {
            if (input[14] >= 7.7719727)
            {
                var365 = -0.006552001;
            }
            else
            {
                var365 = 0.007277747;
            }
        }
    }
    double var366;
    if (input[0] >= 0.018066406)
    {
        if (input[21] >= 487.90457)
        {
            if (input[21] >= 488.7252)
            {
                var366 = -0.0033053216;
            }
            else
            {
                var366 = -0.044282664;
            }
        }
        else
        {
            if (input[21] >= 28.667938)
            {
                var366 = 0.010377536;
            }
            else
            {
                var366 = -0.002480341;
            }
        }
    }
    else
    {
        if (input[14] >= 7.914551)
        {
            var366 = 0.013259107;
        }
        else
        {
            if (input[49] >= 96106.266)
            {
                var366 = -0.0053118095;
            }
            else
            {
                var366 = -0.061618567;
            }
        }
    }
    double var367;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.945)
        {
            if (input[56] >= 77.5)
            {
                var367 = -0.04668026;
            }
            else
            {
                var367 = 0.014814076;
            }
        }
        else
        {
            if (input[56] >= 112.5)
            {
                var367 = -0.01087663;
            }
            else
            {
                var367 = 0.04841297;
            }
        }
    }
    else
    {
        if (input[35] >= 53.30153)
        {
            if (input[35] >= 407.00763)
            {
                var367 = 0.0023575688;
            }
            else
            {
                var367 = 0.033814717;
            }
        }
        else
        {
            if (input[0] >= 0.3095703)
            {
                var367 = 0.0010331374;
            }
            else
            {
                var367 = -0.01904705;
            }
        }
    }
    double var368;
    if (input[28] >= 52.24046)
    {
        if (input[28] >= 232.2939)
        {
            if (input[49] >= 95644.05)
            {
                var368 = 0.010065365;
            }
            else
            {
                var368 = -0.013608577;
            }
        }
        else
        {
            if (input[7] >= 1.7155762)
            {
                var368 = -0.028854957;
            }
            else
            {
                var368 = 0.0064392798;
            }
        }
    }
    else
    {
        if (input[28] >= 48.591606)
        {
            if (input[7] >= 1.7280273)
            {
                var368 = 0.017278304;
            }
            else
            {
                var368 = 0.084158435;
            }
        }
        else
        {
            if (input[14] >= 7.3813477)
            {
                var368 = -0.002805902;
            }
            else
            {
                var368 = 0.017514395;
            }
        }
    }
    double var369;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.14)
            {
                var369 = -0.06258818;
            }
            else
            {
                var369 = 0.024081137;
            }
        }
        else
        {
            var369 = 0.043431055;
        }
    }
    else
    {
        if (input[49] >= 95964.03)
        {
            if (input[56] >= 119.5)
            {
                var369 = -0.022272408;
            }
            else
            {
                var369 = 0.0037653323;
            }
        }
        else
        {
            if (input[49] >= 95720.234)
            {
                var369 = 0.016105665;
            }
            else
            {
                var369 = -0.0012682014;
            }
        }
    }
    double var370;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.415)
        {
            var370 = -0.06026662;
        }
        else
        {
            if (input[56] >= 110.5)
            {
                var370 = -0.02268299;
            }
            else
            {
                var370 = 0.007895471;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var370 = 0.001875026;
            }
            else
            {
                var370 = -0.06631883;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var370 = 0.052660353;
            }
            else
            {
                var370 = 0.0026051335;
            }
        }
    }
    double var371;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var371 = -0.05614513;
            }
            else
            {
                var371 = 0.015315239;
            }
        }
        else
        {
            if (input[7] >= 1.9440918)
            {
                var371 = -0.02920462;
            }
            else
            {
                var371 = 0.054771002;
            }
        }
    }
    else
    {
        if (input[0] >= 7.2072754)
        {
            if (input[49] >= 95004.164)
            {
                var371 = -0.0155657325;
            }
            else
            {
                var371 = 0.005353451;
            }
        }
        else
        {
            if (input[0] >= 0.8823242)
            {
                var371 = 0.017206049;
            }
            else
            {
                var371 = 0.0005331861;
            }
        }
    }
    double var372;
    if (input[0] >= 0.018066406)
    {
        if (input[21] >= 487.90457)
        {
            if (input[21] >= 496.12976)
            {
                var372 = 0.007739894;
            }
            else
            {
                var372 = -0.01380607;
            }
        }
        else
        {
            if (input[21] >= 28.816795)
            {
                var372 = 0.009674786;
            }
            else
            {
                var372 = -0.002872006;
            }
        }
    }
    else
    {
        if (input[14] >= 7.914551)
        {
            var372 = 0.01202187;
        }
        else
        {
            if (input[49] >= 96106.266)
            {
                var372 = -0.0037669984;
            }
            else
            {
                var372 = -0.059635844;
            }
        }
    }
    double var373;
    if (input[49] >= 96108.81)
    {
        if (input[42] >= 24.965)
        {
            if (input[56] >= 77.5)
            {
                var373 = -0.05529001;
            }
            else
            {
                var373 = 0.0145094115;
            }
        }
        else
        {
            if (input[7] >= 1.9440918)
            {
                var373 = -0.02823303;
            }
            else
            {
                var373 = 0.05308351;
            }
        }
    }
    else
    {
        if (input[0] >= 0.015380859)
        {
            if (input[0] >= 6.911133)
            {
                var373 = -0.0051890807;
            }
            else
            {
                var373 = 0.0054417974;
            }
        }
        else
        {
            if (input[21] >= 485.08014)
            {
                var373 = 0.0025141581;
            }
            else
            {
                var373 = -0.05935471;
            }
        }
    }
    double var374;
    if (input[28] >= 52.24046)
    {
        if (input[21] >= 40.240456)
        {
            if (input[21] >= 458.21375)
            {
                var374 = -0.0012714141;
            }
            else
            {
                var374 = 0.022242822;
            }
        }
        else
        {
            if (input[49] >= 95997.055)
            {
                var374 = -0.033661064;
            }
            else
            {
                var374 = -0.003220188;
            }
        }
    }
    else
    {
        if (input[28] >= 48.591606)
        {
            if (input[7] >= 1.7280273)
            {
                var374 = 0.015898857;
            }
            else
            {
                var374 = 0.08066732;
            }
        }
        else
        {
            if (input[21] >= 77.19466)
            {
                var374 = -0.0039509214;
            }
            else
            {
                var374 = 0.015132794;
            }
        }
    }
    double var375;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.14)
            {
                var375 = -0.059344538;
            }
            else
            {
                var375 = 0.0250186;
            }
        }
        else
        {
            var375 = 0.04295111;
        }
    }
    else
    {
        if (input[0] >= 0.2644043)
        {
            if (input[21] >= 28.931297)
            {
                var375 = 0.00725891;
            }
            else
            {
                var375 = -0.0044522043;
            }
        }
        else
        {
            if (input[21] >= 12.20229)
            {
                var375 = -0.015204312;
            }
            else
            {
                var375 = 0.012987073;
            }
        }
    }
    double var376;
    if (input[42] >= 25.045)
    {
        if (input[49] >= 95979.27)
        {
            if (input[42] >= 25.455)
            {
                var376 = -0.031469468;
            }
            else
            {
                var376 = 0.00046036346;
            }
        }
        else
        {
            if (input[14] >= 7.836914)
            {
                var376 = -0.011935758;
            }
            else
            {
                var376 = 0.006717168;
            }
        }
    }
    else
    {
        if (input[21] >= 28.687023)
        {
            if (input[56] >= 99.5)
            {
                var376 = 0.031928692;
            }
            else
            {
                var376 = -0.030009566;
            }
        }
        else
        {
            if (input[7] >= 2.8691406)
            {
                var376 = -0.06663304;
            }
            else
            {
                var376 = 0.0018438416;
            }
        }
    }
    double var377;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.415)
        {
            var377 = -0.059746332;
        }
        else
        {
            if (input[56] >= 113.5)
            {
                var377 = -0.026190495;
            }
            else
            {
                var377 = 0.006013145;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 96017.375)
            {
                var377 = -0.05442344;
            }
            else
            {
                var377 = 0.0016047258;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var377 = 0.050612967;
            }
            else
            {
                var377 = 0.0023980874;
            }
        }
    }
    double var378;
    if (input[21] >= 487.90457)
    {
        if (input[42] >= 25.46)
        {
            if (input[49] >= 95925.94)
            {
                var378 = -0.05919499;
            }
            else
            {
                var378 = -0.0005205241;
            }
        }
        else
        {
            if (input[42] >= 25.3)
            {
                var378 = 0.045669973;
            }
            else
            {
                var378 = -0.004790151;
            }
        }
    }
    else
    {
        if (input[0] >= 0.036865234)
        {
            if (input[49] >= 96078.33)
            {
                var378 = -0.0117065795;
            }
            else
            {
                var378 = 0.0059371567;
            }
        }
        else
        {
            if (input[35] >= 484.23663)
            {
                var378 = 0.014940269;
            }
            else
            {
                var378 = -0.049614534;
            }
        }
    }
    double var379;
    if (input[42] >= 25.045)
    {
        if (input[49] >= 95979.27)
        {
            if (input[42] >= 25.455)
            {
                var379 = -0.029244525;
            }
            else
            {
                var379 = 0.00002010611;
            }
        }
        else
        {
            if (input[0] >= 1.9448242)
            {
                var379 = -0.0066010854;
            }
            else
            {
                var379 = 0.008215723;
            }
        }
    }
    else
    {
        if (input[35] >= 24.93893)
        {
            if (input[42] >= 24.85)
            {
                var379 = 0.040547874;
            }
            else
            {
                var379 = -0.0057757096;
            }
        }
        else
        {
            if (input[56] >= 119.5)
            {
                var379 = -0.06895035;
            }
            else
            {
                var379 = 0.005813711;
            }
        }
    }
    double var380;
    if (input[49] >= 96108.81)
    {
        if (input[7] >= 1.9438477)
        {
            if (input[0] >= 0.092285156)
            {
                var380 = -0.049766686;
            }
            else
            {
                var380 = 0.016513644;
            }
        }
        else
        {
            if (input[42] >= 24.965)
            {
                var380 = -0.017688744;
            }
            else
            {
                var380 = 0.050889887;
            }
        }
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 28.385)
            {
                var380 = -0.046501663;
            }
            else
            {
                var380 = -0.00008980542;
            }
        }
        else
        {
            if (input[42] >= 25.195)
            {
                var380 = 0.004246956;
            }
            else
            {
                var380 = 0.047251184;
            }
        }
    }
    double var381;
    if (input[28] >= 52.24046)
    {
        if (input[28] >= 232.2939)
        {
            if (input[49] >= 95628.81)
            {
                var381 = 0.008732781;
            }
            else
            {
                var381 = -0.013520422;
            }
        }
        else
        {
            if (input[21] >= 30.85878)
            {
                var381 = -0.00045640054;
            }
            else
            {
                var381 = -0.035878528;
            }
        }
    }
    else
    {
        if (input[14] >= 7.9821777)
        {
            var381 = -0.05815926;
        }
        else
        {
            if (input[28] >= 48.591606)
            {
                var381 = 0.044168692;
            }
            else
            {
                var381 = 0.0058677765;
            }
        }
    }
    double var382;
    if (input[49] >= 96088.484)
    {
        if (input[42] >= 25.195)
        {
            if (input[56] >= 77.5)
            {
                var382 = -0.03880884;
            }
            else
            {
                var382 = 0.0133253625;
            }
        }
        else
        {
            if (input[56] >= 113.5)
            {
                var382 = -0.03637886;
            }
            else
            {
                var382 = 0.027737234;
            }
        }
    }
    else
    {
        if (input[14] >= 7.7719727)
        {
            if (input[42] >= 25.15)
            {
                var382 = -0.009002277;
            }
            else
            {
                var382 = 0.027926475;
            }
        }
        else
        {
            if (input[7] >= 3.46167)
            {
                var382 = -0.027550474;
            }
            else
            {
                var382 = 0.0055750622;
            }
        }
    }
    double var383;
    if (input[49] >= 96108.81)
    {
        if (input[7] >= 1.9438477)
        {
            if (input[0] >= 0.092285156)
            {
                var383 = -0.048527505;
            }
            else
            {
                var383 = 0.015735207;
            }
        }
        else
        {
            if (input[42] >= 24.965)
            {
                var383 = -0.01734862;
            }
            else
            {
                var383 = 0.04881035;
            }
        }
    }
    else
    {
        if (input[56] >= 113.5)
        {
            if (input[42] >= 24.79)
            {
                var383 = -0.00041446133;
            }
            else
            {
                var383 = -0.053935148;
            }
        }
        else
        {
            if (input[42] >= 25.195)
            {
                var383 = 0.0041152397;
            }
            else
            {
                var383 = 0.044736274;
            }
        }
    }
    double var384;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.235)
            {
                var384 = -0.056442242;
            }
            else
            {
                var384 = 0.011176513;
            }
        }
        else
        {
            var384 = 0.042304453;
        }
    }
    else
    {
        if (input[49] >= 96078.33)
        {
            if (input[42] >= 25.335)
            {
                var384 = -0.04753256;
            }
            else
            {
                var384 = -0.0019745263;
            }
        }
        else
        {
            if (input[14] >= 7.805908)
            {
                var384 = -0.0068156454;
            }
            else
            {
                var384 = 0.005066958;
            }
        }
    }
    double var385;
    if (input[21] >= 487.90457)
    {
        if (input[21] >= 488.72137)
        {
            if (input[56] >= 70.5)
            {
                var385 = -0.0004057705;
            }
            else
            {
                var385 = -0.03979606;
            }
        }
        else
        {
            if (input[56] >= 114.5)
            {
                var385 = -0.065042324;
            }
            else
            {
                var385 = 0.010455518;
            }
        }
    }
    else
    {
        if (input[21] >= 28.667938)
        {
            if (input[42] >= 25.154999)
            {
                var385 = 0.0047313683;
            }
            else
            {
                var385 = 0.030612176;
            }
        }
        else
        {
            if (input[28] >= 53.48855)
            {
                var385 = -0.011207964;
            }
            else
            {
                var385 = 0.012323463;
            }
        }
    }
    double var386;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.415)
        {
            var386 = -0.058683064;
        }
        else
        {
            if (input[56] >= 109.5)
            {
                var386 = -0.0200663;
            }
            else
            {
                var386 = 0.007561892;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var386 = 0.0010957283;
            }
            else
            {
                var386 = -0.06291788;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var386 = 0.048086755;
            }
            else
            {
                var386 = 0.0012596663;
            }
        }
    }
    double var387;
    if (input[35] >= 49.33206)
    {
        if (input[35] >= 127.53435)
        {
            if (input[7] >= 2.1716309)
            {
                var387 = -0.011165517;
            }
            else
            {
                var387 = 0.004914254;
            }
        }
        else
        {
            if (input[0] >= 7.5185547)
            {
                var387 = -0.025100177;
            }
            else
            {
                var387 = 0.038854085;
            }
        }
    }
    else
    {
        if (input[35] >= 42.687023)
        {
            if (input[42] >= 26.55)
            {
                var387 = -0.066469595;
            }
            else
            {
                var387 = -0.011653363;
            }
        }
        else
        {
            if (input[28] >= 73.57252)
            {
                var387 = -0.00810378;
            }
            else
            {
                var387 = 0.0063183927;
            }
        }
    }
    double var388;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.235)
            {
                var388 = -0.054235686;
            }
            else
            {
                var388 = 0.011652166;
            }
        }
        else
        {
            var388 = 0.040991783;
        }
    }
    else
    {
        if (input[0] >= 0.2644043)
        {
            if (input[28] >= 35.156487)
            {
                var388 = -0.00019992328;
            }
            else
            {
                var388 = 0.011826882;
            }
        }
        else
        {
            if (input[21] >= 463.88165)
            {
                var388 = -0.018358942;
            }
            else
            {
                var388 = 0.004923616;
            }
        }
    }
    double var389;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.415)
        {
            var389 = -0.058279406;
        }
        else
        {
            if (input[0] >= 1.2756348)
            {
                var389 = 0.017074754;
            }
            else
            {
                var389 = -0.012547254;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[49] >= 96017.375)
            {
                var389 = -0.052564483;
            }
            else
            {
                var389 = 0.0011885834;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var389 = 0.046843644;
            }
            else
            {
                var389 = 0.0016572739;
            }
        }
    }
    double var390;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.235)
            {
                var390 = -0.052651055;
            }
            else
            {
                var390 = 0.011124399;
            }
        }
        else
        {
            var390 = 0.039921444;
        }
    }
    else
    {
        if (input[35] >= 49.33206)
        {
            if (input[35] >= 405.05344)
            {
                var390 = 0.00010376994;
            }
            else
            {
                var390 = 0.025232598;
            }
        }
        else
        {
            if (input[35] >= 42.73664)
            {
                var390 = -0.034868658;
            }
            else
            {
                var390 = -0.001877641;
            }
        }
    }
    double var391;
    if (input[49] >= 96108.81)
    {
        if (input[7] >= 1.9438477)
        {
            if (input[21] >= 498.687)
            {
                var391 = 0.025747389;
            }
            else
            {
                var391 = -0.046072215;
            }
        }
        else
        {
            if (input[42] >= 24.965)
            {
                var391 = -0.015645394;
            }
            else
            {
                var391 = 0.047067914;
            }
        }
    }
    else
    {
        if (input[0] >= 1.9448242)
        {
            if (input[35] >= 89.270996)
            {
                var391 = 0.0052098986;
            }
            else
            {
                var391 = -0.013378546;
            }
        }
        else
        {
            if (input[0] >= 0.8823242)
            {
                var391 = 0.018654613;
            }
            else
            {
                var391 = -0.0004889827;
            }
        }
    }
    double var392;
    if (input[42] >= 28.505001)
    {
        if (input[56] >= 108.0)
        {
            var392 = -0.04937672;
        }
        else
        {
            if (input[56] >= 81.5)
            {
                var392 = 0.018771729;
            }
            else
            {
                var392 = -0.038409576;
            }
        }
    }
    else
    {
        if (input[7] >= 2.8327637)
        {
            if (input[0] >= 0.5410156)
            {
                var392 = -0.0011744075;
            }
            else
            {
                var392 = -0.033808477;
            }
        }
        else
        {
            if (input[7] >= 2.80542)
            {
                var392 = 0.069922216;
            }
            else
            {
                var392 = 0.0013326062;
            }
        }
    }
    double var393;
    if (input[21] >= 487.90457)
    {
        if (input[21] >= 496.12976)
        {
            if (input[21] >= 499.33588)
            {
                var393 = -0.018153282;
            }
            else
            {
                var393 = 0.015954373;
            }
        }
        else
        {
            if (input[0] >= 0.064697266)
            {
                var393 = -0.014736257;
            }
            else
            {
                var393 = 0.052934427;
            }
        }
    }
    else
    {
        if (input[49] >= 96022.45)
        {
            if (input[42] >= 25.445)
            {
                var393 = -0.050513297;
            }
            else
            {
                var393 = -0.0004572135;
            }
        }
        else
        {
            if (input[42] >= 25.915)
            {
                var393 = 0.002093982;
            }
            else
            {
                var393 = 0.024901811;
            }
        }
    }
    double var394;
    if (input[0] >= 0.015380859)
    {
        if (input[49] >= 96108.81)
        {
            if (input[56] >= 77.5)
            {
                var394 = -0.0277605;
            }
            else
            {
                var394 = 0.02353569;
            }
        }
        else
        {
            if (input[0] >= 1.6516113)
            {
                var394 = -0.00484081;
            }
            else
            {
                var394 = 0.0042672195;
            }
        }
    }
    else
    {
        if (input[42] >= 25.04)
        {
            var394 = -0.05083848;
        }
        else
        {
            var394 = 0.010418789;
        }
    }
    double var395;
    if (input[0] >= 0.25268555)
    {
        if (input[28] >= 35.156487)
        {
            if (input[28] >= 37.9771)
            {
                var395 = -0.000004944943;
            }
            else
            {
                var395 = -0.055640545;
            }
        }
        else
        {
            if (input[35] >= 479.12213)
            {
                var395 = -0.0032114906;
            }
            else
            {
                var395 = 0.017483843;
            }
        }
    }
    else
    {
        if (input[21] >= 463.88165)
        {
            if (input[56] >= 131.5)
            {
                var395 = -0.045994155;
            }
            else
            {
                var395 = -0.0046645286;
            }
        }
        else
        {
            if (input[49] >= 95958.96)
            {
                var395 = -0.028876835;
            }
            else
            {
                var395 = 0.015214036;
            }
        }
    }
    double var396;
    if (input[0] >= 7.974121)
    {
        if (input[56] >= 109.0)
        {
            if (input[42] >= 25.235)
            {
                var396 = -0.050742406;
            }
            else
            {
                var396 = 0.011333942;
            }
        }
        else
        {
            var396 = 0.039377585;
        }
    }
    else
    {
        if (input[0] >= 7.971924)
        {
            var396 = 0.06526683;
        }
        else
        {
            if (input[35] >= 52.744278)
            {
                var396 = 0.0035593777;
            }
            else
            {
                var396 = -0.0039458303;
            }
        }
    }
    double var397;
    if (input[42] >= 28.485)
    {
        if (input[56] >= 111.5)
        {
            var397 = -0.050587114;
        }
        else
        {
            if (input[7] >= 1.8632812)
            {
                var397 = -0.027551323;
            }
            else
            {
                var397 = 0.029292954;
            }
        }
    }
    else
    {
        if (input[42] >= 26.195)
        {
            if (input[42] >= 27.09)
            {
                var397 = -0.00054087926;
            }
            else
            {
                var397 = 0.020458013;
            }
        }
        else
        {
            if (input[42] >= 26.125)
            {
                var397 = -0.06250634;
            }
            else
            {
                var397 = -0.0017641189;
            }
        }
    }
    double var398;
    if (input[49] >= 96078.33)
    {
        if (input[42] >= 25.415)
        {
            var398 = -0.057615872;
        }
        else
        {
            if (input[0] >= 1.2756348)
            {
                var398 = 0.016221585;
            }
            else
            {
                var398 = -0.012064556;
            }
        }
    }
    else
    {
        if (input[42] >= 25.475)
        {
            if (input[42] >= 25.625)
            {
                var398 = 0.0007899453;
            }
            else
            {
                var398 = -0.060682382;
            }
        }
        else
        {
            if (input[42] >= 25.335)
            {
                var398 = 0.045709927;
            }
            else
            {
                var398 = 0.0015979061;
            }
        }
    }
    double var399;
    if (input[21] >= 487.90457)
    {
        if (input[21] >= 496.12976)
        {
            if (input[21] >= 499.33588)
            {
                var399 = -0.017514247;
            }
            else
            {
                var399 = 0.015172819;
            }
        }
        else
        {
            if (input[0] >= 0.064697266)
            {
                var399 = -0.014200868;
            }
            else
            {
                var399 = 0.051465936;
            }
        }
    }
    else
    {
        if (input[21] >= 28.667938)
        {
            if (input[42] >= 25.154999)
            {
                var399 = 0.004144075;
            }
            else
            {
                var399 = 0.0292273;
            }
        }
        else
        {
            if (input[49] >= 95997.055)
            {
                var399 = -0.02268341;
            }
            else
            {
                var399 = 0.002354659;
            }
        }
    }
    double var400;
    if (input[0] >= 0.25268555)
    {
        if (input[0] >= 1.9448242)
        {
            if (input[42] >= 25.465)
            {
                var400 = -0.008614896;
            }
            else
            {
                var400 = 0.017398417;
            }
        }
        else
        {
            if (input[49] >= 95979.27)
            {
                var400 = -0.0050300495;
            }
            else
            {
                var400 = 0.012076812;
            }
        }
    }
    else
    {
        if (input[0] >= 0.24291992)
        {
            var400 = -0.07129545;
        }
        else
        {
            if (input[7] >= 1.8198242)
            {
                var400 = -0.015753677;
            }
            else
            {
                var400 = 0.006885964;
            }
        }
    }
    double var401;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var401 = -0.049586777;
            }
            else
            {
                var401 = 0.096491225;
            }
        }
        else
        {
            var401 = 0.24802616;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var401 = -0.062413044;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var401 = 0.23800384;
            }
            else
            {
                var401 = 0.11490559;
            }
        }
    }
    double var402;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var402 = -0.04939724;
            }
            else
            {
                var402 = 0.08905976;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var402 = 0.059268624;
            }
            else
            {
                var402 = 0.19578026;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var402 = -0.061448045;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var402 = 0.1933418;
            }
            else
            {
                var402 = 0.09955357;
            }
        }
    }
    double var403;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var403 = -0.049190544;
            }
            else
            {
                var403 = 0.082499586;
            }
        }
        else
        {
            var403 = 0.16253124;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var403 = -0.06056553;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var403 = 0.16464736;
            }
            else
            {
                var403 = 0.087116495;
            }
        }
    }
    double var404;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var404 = -0.048231587;
            }
            else
            {
                var404 = 0.07884722;
            }
        }
        else
        {
            var404 = 0.14003742;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var404 = -0.05976528;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var404 = 0.14381778;
            }
            else
            {
                var404 = 0.077398196;
            }
        }
    }
    double var405;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var405 = -0.04727665;
            }
            else
            {
                var405 = 0.075596526;
            }
        }
        else
        {
            var405 = 0.123724364;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var405 = -0.059033513;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var405 = 0.12829293;
            }
            else
            {
                var405 = 0.06937686;
            }
        }
    }
    double var406;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var406 = -0.04632697;
            }
            else
            {
                var406 = 0.07269278;
            }
        }
        else
        {
            var406 = 0.11139494;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var406 = -0.058361437;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var406 = 0.116613105;
            }
            else
            {
                var406 = 0.0623144;
            }
        }
    }
    double var407;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var407 = -0.045383736;
            }
            else
            {
                var407 = 0.07008814;
            }
        }
        else
        {
            var407 = 0.10178822;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var407 = -0.057753753;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var407 = 0.10719808;
            }
            else
            {
                var407 = 0.05667845;
            }
        }
    }
    double var408;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var408 = -0.044448026;
            }
            else
            {
                var408 = 0.06774093;
            }
        }
        else
        {
            var408 = 0.094125316;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var408 = -0.057193633;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var408 = 0.09974799;
            }
            else
            {
                var408 = 0.051595654;
            }
        }
    }
    double var409;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var409 = -0.04380174;
            }
            else
            {
                var409 = 0.06464585;
            }
        }
        else
        {
            var409 = 0.087891355;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var409 = -0.056682188;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var409 = 0.09359429;
            }
            else
            {
                var409 = 0.04733951;
            }
        }
    }
    double var410;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var410 = -0.04287719;
            }
            else
            {
                var410 = 0.06277198;
            }
        }
        else
        {
            var410 = 0.08275518;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var410 = -0.05620742;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var410 = 0.088493615;
            }
            else
            {
                var410 = 0.043290086;
            }
        }
    }
    double var411;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var411 = -0.042229198;
            }
            else
            {
                var411 = 0.060164463;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var411 = 0.027581612;
            }
            else
            {
                var411 = 0.07864461;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var411 = -0.0557775;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var411 = 0.084636085;
            }
            else
            {
                var411 = 0.040196683;
            }
        }
    }
    double var412;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var412 = -0.041318342;
            }
            else
            {
                var412 = 0.05864517;
            }
        }
        else
        {
            var412 = 0.074850254;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var412 = -0.055383313;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var412 = 0.08127981;
            }
            else
            {
                var412 = 0.037451368;
            }
        }
    }
    double var413;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.465)
        {
            if (input[7] >= 2.040039)
            {
                var413 = 0.015105002;
            }
            else
            {
                var413 = -0.036007654;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var413 = 0.029138839;
            }
            else
            {
                var413 = 0.07194543;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var413 = -0.05501298;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var413 = 0.07801136;
            }
            else
            {
                var413 = 0.034635164;
            }
        }
    }
    double var414;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.465)
        {
            if (input[28] >= 483.69464)
            {
                var414 = -0.0350736;
            }
            else
            {
                var414 = 0.015653515;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var414 = 0.028975014;
            }
            else
            {
                var414 = 0.06930339;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var414 = -0.054673593;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var414 = 0.07545354;
            }
            else
            {
                var414 = 0.032330643;
            }
        }
    }
    double var415;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.465)
        {
            if (input[7] >= 2.040039)
            {
                var415 = 0.015889375;
            }
            else
            {
                var415 = -0.03453044;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var415 = 0.027998531;
            }
            else
            {
                var415 = 0.06702348;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var415 = -0.054354608;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var415 = 0.07302042;
            }
            else
            {
                var415 = 0.029817468;
            }
        }
    }
    double var416;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var416 = -0.04070612;
            }
            else
            {
                var416 = 0.056140967;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var416 = 0.023414096;
            }
            else
            {
                var416 = 0.0650413;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var416 = -0.054060347;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var416 = 0.07091466;
            }
            else
            {
                var416 = 0.027662007;
            }
        }
    }
    double var417;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var417 = -0.040379144;
            }
            else
            {
                var417 = 0.053097505;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var417 = 0.022207757;
            }
            else
            {
                var417 = 0.06331497;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var417 = -0.053788155;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var417 = 0.06907701;
            }
            else
            {
                var417 = 0.026003972;
            }
        }
    }
    double var418;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.465)
        {
            if (input[28] >= 483.69464)
            {
                var418 = -0.034601267;
            }
            else
            {
                var418 = 0.01498794;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var418 = 0.024986284;
            }
            else
            {
                var418 = 0.061799616;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var418 = -0.053530492;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var418 = 0.0670745;
            }
            else
            {
                var418 = 0.023999875;
            }
        }
    }
    double var419;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[35] >= 250.3626)
            {
                var419 = -0.04192255;
            }
            else
            {
                var419 = 0.049355682;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var419 = 0.02105444;
            }
            else
            {
                var419 = 0.06046753;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var419 = -0.053294446;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var419 = 0.06550217;
            }
            else
            {
                var419 = 0.022766208;
            }
        }
    }
    double var420;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.465)
        {
            if (input[7] >= 2.040039)
            {
                var420 = 0.0153256375;
            }
            else
            {
                var420 = -0.033784382;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var420 = 0.023697484;
            }
            else
            {
                var420 = 0.05928914;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var420 = -0.053071328;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var420 = 0.06408294;
            }
            else
            {
                var420 = 0.021259528;
            }
        }
    }
    double var421;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.435001)
        {
            if (input[56] >= 67.5)
            {
                var421 = -0.03974018;
            }
            else
            {
                var421 = 0.048820563;
            }
        }
        else
        {
            if (input[42] >= 27.415)
            {
                var421 = 0.019237166;
            }
            else
            {
                var421 = 0.05824847;
            }
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var421 = -0.05286203;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var421 = 0.06288335;
            }
            else
            {
                var421 = 0.020001791;
            }
        }
    }
    double var422;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.415)
        {
            if (input[14] >= 7.362549)
            {
                var422 = -0.020762905;
            }
            else
            {
                var422 = 0.064495884;
            }
        }
        else
        {
            var422 = 0.05732463;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var422 = -0.0526655;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var422 = 0.061749514;
            }
            else
            {
                var422 = 0.018746456;
            }
        }
    }
    double var423;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.415)
        {
            if (input[35] >= 250.3626)
            {
                var423 = -0.040793695;
            }
            else
            {
                var423 = 0.038586274;
            }
        }
        else
        {
            var423 = 0.056497928;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var423 = -0.05248495;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var423 = 0.060790267;
            }
            else
            {
                var423 = 0.017982844;
            }
        }
    }
    double var424;
    if (input[49] >= 96850.555)
    {
        if (input[42] >= 27.415)
        {
            if (input[56] >= 67.5)
            {
                var424 = -0.03845049;
            }
            else
            {
                var424 = 0.038758744;
            }
        }
        else
        {
            var424 = 0.0557533;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            var424 = -0.052310277;
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var424 = 0.059830524;
            }
            else
            {
                var424 = 0.016666157;
            }
        }
    }
    double var425;
    if (input[49] >= 96873.42)
    {
        var425 = 0.05540983;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var425 = 0.01570725;
            }
            else
            {
                var425 = -0.05214674;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var425 = 0.058903106;
            }
            else
            {
                var425 = 0.015683629;
            }
        }
    }
    double var426;
    if (input[49] >= 96873.42)
    {
        var426 = 0.054750044;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var426 = 0.014502293;
            }
            else
            {
                var426 = -0.0519935;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var426 = 0.05808556;
            }
            else
            {
                var426 = 0.014977494;
            }
        }
    }
    double var427;
    if (input[49] >= 96873.42)
    {
        var427 = 0.054192986;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var427 = 0.013446919;
            }
            else
            {
                var427 = -0.05184486;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var427 = 0.05730905;
            }
            else
            {
                var427 = 0.014072517;
            }
        }
    }
    double var428;
    if (input[49] >= 96873.42)
    {
        var428 = 0.05367747;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var428 = 0.0123488465;
            }
            else
            {
                var428 = -0.051707458;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var428 = 0.05660333;
            }
            else
            {
                var428 = 0.013530758;
            }
        }
    }
    double var429;
    if (input[49] >= 96873.42)
    {
        var429 = 0.053227544;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var429 = 0.010937011;
            }
            else
            {
                var429 = -0.05157381;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var429 = 0.055944778;
            }
            else
            {
                var429 = 0.012874066;
            }
        }
    }
    double var430;
    if (input[49] >= 96873.42)
    {
        var430 = 0.05276195;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var430 = 0.009656916;
            }
            else
            {
                var430 = -0.051447343;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var430 = 0.05528864;
            }
            else
            {
                var430 = 0.0120838955;
            }
        }
    }
    double var431;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var431 = 0.01893002;
        }
        else
        {
            var431 = 0.05284741;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var431 = 0.008907394;
            }
            else
            {
                var431 = -0.051328834;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var431 = 0.054664113;
            }
            else
            {
                var431 = 0.011642058;
            }
        }
    }
    double var432;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var432 = 0.01791541;
        }
        else
        {
            var432 = 0.052446704;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var432 = 0.008638554;
            }
            else
            {
                var432 = -0.051214315;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var432 = 0.0541143;
            }
            else
            {
                var432 = 0.011028973;
            }
        }
    }
    double var433;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var433 = 0.016863694;
        }
        else
        {
            var433 = 0.052139707;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var433 = 0.007352548;
            }
            else
            {
                var433 = -0.05110365;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var433 = 0.05355952;
            }
            else
            {
                var433 = 0.010616185;
            }
        }
    }
    double var434;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var434 = 0.015690958;
        }
        else
        {
            var434 = 0.051821303;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var434 = 0.006284365;
            }
            else
            {
                var434 = -0.05099977;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var434 = 0.053022962;
            }
            else
            {
                var434 = 0.010186419;
            }
        }
    }
    double var435;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var435 = 0.014659745;
        }
        else
        {
            var435 = 0.051545292;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var435 = 0.0056088455;
            }
            else
            {
                var435 = -0.050899684;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var435 = 0.052537907;
            }
            else
            {
                var435 = 0.00982491;
            }
        }
    }
    double var436;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var436 = 0.013702519;
        }
        else
        {
            var436 = 0.051273283;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var436 = 0.0051623303;
            }
            else
            {
                var436 = -0.050801635;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var436 = 0.05199025;
            }
            else
            {
                var436 = 0.00914853;
            }
        }
    }
    double var437;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var437 = 0.012624437;
        }
        else
        {
            var437 = 0.051002827;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var437 = 0.004225901;
            }
            else
            {
                var437 = -0.050708164;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var437 = 0.05151849;
            }
            else
            {
                var437 = 0.008809829;
            }
        }
    }
    double var438;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var438 = 0.011897809;
        }
        else
        {
            var438 = 0.05079332;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var438 = 0.0042244247;
            }
            else
            {
                var438 = -0.050615616;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var438 = 0.0509493;
            }
            else
            {
                var438 = 0.007982634;
            }
        }
    }
    double var439;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var439 = 0.011304682;
        }
        else
        {
            var439 = 0.050571837;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var439 = 0.0035767604;
            }
            else
            {
                var439 = -0.050525147;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var439 = 0.05046333;
            }
            else
            {
                var439 = 0.0075543444;
            }
        }
    }
    double var440;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var440 = 0.0104481485;
        }
        else
        {
            var440 = 0.05031823;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var440 = 0.0031550177;
            }
            else
            {
                var440 = -0.05043844;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var440 = 0.05003236;
            }
            else
            {
                var440 = 0.0071670893;
            }
        }
    }
    double var441;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 235.0)
        {
            var441 = 0.009663244;
        }
        else
        {
            var441 = 0.050084587;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var441 = 0.002936025;
            }
            else
            {
                var441 = -0.05035339;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var441 = 0.049614277;
            }
            else
            {
                var441 = 0.0069281845;
            }
        }
    }
    double var442;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 232.5)
        {
            var442 = 0.011786652;
        }
        else
        {
            var442 = 0.04988479;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var442 = 0.0029714145;
            }
            else
            {
                var442 = -0.050269436;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var442 = 0.04916404;
            }
            else
            {
                var442 = 0.0066026445;
            }
        }
    }
    double var443;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 232.5)
        {
            var443 = 0.011446861;
        }
        else
        {
            var443 = 0.049705647;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var443 = 0.002667019;
            }
            else
            {
                var443 = -0.050186217;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var443 = 0.04872844;
            }
            else
            {
                var443 = 0.0062670307;
            }
        }
    }
    double var444;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 232.5)
        {
            var444 = 0.011039672;
        }
        else
        {
            var444 = 0.04949687;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var444 = 0.002553698;
            }
            else
            {
                var444 = -0.05010288;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var444 = 0.048233345;
            }
            else
            {
                var444 = 0.0056189937;
            }
        }
    }
    double var445;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 232.5)
        {
            var445 = 0.01025767;
        }
        else
        {
            var445 = 0.04926015;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var445 = 0.0026001583;
            }
            else
            {
                var445 = -0.050022423;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var445 = 0.047838356;
            }
            else
            {
                var445 = 0.0054165903;
            }
        }
    }
    double var446;
    if (input[49] >= 94798.516)
    {
        if (input[49] >= 96850.555)
        {
            if (input[42] >= 27.415)
            {
                var446 = -0.005287732;
            }
            else
            {
                var446 = 0.048595276;
            }
        }
        else
        {
            var446 = -0.04994061;
        }
    }
    else
    {
        if (input[42] >= 28.555)
        {
            var446 = 0.04740266;
        }
        else
        {
            if (input[42] >= 28.455)
            {
                var446 = -0.0082865795;
            }
            else
            {
                var446 = 0.013375409;
            }
        }
    }
    double var447;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 230.5)
        {
            var447 = 0.009647809;
        }
        else
        {
            var447 = 0.048909824;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var447 = 0.002054345;
            }
            else
            {
                var447 = -0.0498592;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var447 = 0.04690451;
            }
            else
            {
                var447 = 0.004560175;
            }
        }
    }
    double var448;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 230.5)
        {
            var448 = 0.009276922;
        }
        else
        {
            var448 = 0.048690256;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var448 = 0.001860188;
            }
            else
            {
                var448 = -0.04977866;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var448 = 0.046464596;
            }
            else
            {
                var448 = 0.0042757792;
            }
        }
    }
    double var449;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 230.5)
        {
            var449 = 0.009121285;
        }
        else
        {
            var449 = 0.048503343;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var449 = 0.001930948;
            }
            else
            {
                var449 = -0.049698573;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var449 = 0.046073135;
            }
            else
            {
                var449 = 0.0041831345;
            }
        }
    }
    double var450;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 230.5)
        {
            var450 = 0.008686206;
        }
        else
        {
            var450 = 0.048284646;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var450 = 0.0017067016;
            }
            else
            {
                var450 = -0.049617756;
            }
        }
        else
        {
            if (input[49] >= 94671.586)
            {
                var450 = 0.0017837839;
            }
            else
            {
                var450 = 0.025591666;
            }
        }
    }
    double var451;
    if (input[49] >= 94798.516)
    {
        if (input[49] >= 96850.555)
        {
            if (input[42] >= 27.415)
            {
                var451 = -0.0066904486;
            }
            else
            {
                var451 = 0.047727402;
            }
        }
        else
        {
            var451 = -0.049537923;
        }
    }
    else
    {
        if (input[42] >= 28.555)
        {
            var451 = 0.04554581;
        }
        else
        {
            if (input[42] >= 28.455)
            {
                var451 = -0.009536979;
            }
            else
            {
                var451 = 0.0116244955;
            }
        }
    }
    double var452;
    if (input[49] >= 94798.516)
    {
        if (input[49] >= 96850.555)
        {
            if (input[42] >= 27.415)
            {
                var452 = -0.006192609;
            }
            else
            {
                var452 = 0.04755096;
            }
        }
        else
        {
            var452 = -0.049455468;
        }
    }
    else
    {
        if (input[42] >= 28.555)
        {
            var452 = 0.045172025;
        }
        else
        {
            if (input[42] >= 28.455)
            {
                var452 = -0.009110159;
            }
            else
            {
                var452 = 0.011084984;
            }
        }
    }
    double var453;
    if (input[49] >= 94732.516)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 210.5)
            {
                var453 = 0.00868522;
            }
            else
            {
                var453 = 0.047733754;
            }
        }
        else
        {
            if (input[49] >= 94798.516)
            {
                var453 = -0.043947652;
            }
            else
            {
                var453 = -0.007602134;
            }
        }
    }
    else
    {
        if (input[42] >= 28.455)
        {
            if (input[42] >= 28.555)
            {
                var453 = 0.044749033;
            }
            else
            {
                var453 = -0.008779625;
            }
        }
        else
        {
            if (input[42] >= 28.39)
            {
                var453 = 0.052728545;
            }
            else
            {
                var453 = 0.0068752067;
            }
        }
    }
    double var454;
    if (input[49] >= 94798.516)
    {
        if (input[49] >= 96850.555)
        {
            if (input[42] >= 27.415)
            {
                var454 = -0.0047588525;
            }
            else
            {
                var454 = 0.04722033;
            }
        }
        else
        {
            var454 = -0.049296234;
        }
    }
    else
    {
        if (input[49] >= 94671.586)
        {
            if (input[14] >= 7.6748047)
            {
                var454 = 0.015602331;
            }
            else
            {
                var454 = -0.007043624;
            }
        }
        else
        {
            if (input[56] >= 139.0)
            {
                var454 = 0.060781695;
            }
            else
            {
                var454 = 0.0045248824;
            }
        }
    }
    double var455;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 163.0)
        {
            var455 = 0.008519887;
        }
        else
        {
            var455 = 0.04732599;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var455 = 0.0019989703;
            }
            else
            {
                var455 = -0.04920963;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var455 = 0.044134848;
            }
            else
            {
                var455 = 0.002652878;
            }
        }
    }
    double var456;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 163.0)
        {
            var456 = 0.008160693;
        }
        else
        {
            var456 = 0.047069836;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var456 = 0.0017155132;
            }
            else
            {
                var456 = -0.049123015;
            }
        }
        else
        {
            if (input[49] >= 94671.586)
            {
                var456 = 0.0006681204;
            }
            else
            {
                var456 = 0.022722417;
            }
        }
    }
    double var457;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 146.5)
        {
            var457 = 0.008145164;
        }
        else
        {
            var457 = 0.046816293;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var457 = 0.0016337719;
            }
            else
            {
                var457 = -0.04903349;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var457 = 0.04362134;
            }
            else
            {
                var457 = 0.0021359804;
            }
        }
    }
    double var458;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 146.5)
        {
            var458 = 0.007824017;
        }
        else
        {
            var458 = 0.046572514;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var458 = 0.0014199242;
            }
            else
            {
                var458 = -0.048942503;
            }
        }
        else
        {
            if (input[21] >= 478.85114)
            {
                var458 = -0.005226318;
            }
            else
            {
                var458 = 0.010606403;
            }
        }
    }
    double var459;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 146.5)
        {
            var459 = 0.00787669;
        }
        else
        {
            var459 = 0.046362363;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var459 = 0.0018563217;
            }
            else
            {
                var459 = -0.04884897;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var459 = 0.043182712;
            }
            else
            {
                var459 = 0.0017122306;
            }
        }
    }
    double var460;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 146.5)
        {
            var460 = 0.00755712;
        }
        else
        {
            var460 = 0.046093803;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var460 = 0.0016760522;
            }
            else
            {
                var460 = -0.048753675;
            }
        }
        else
        {
            if (input[49] >= 94671.586)
            {
                var460 = -0.00017411451;
            }
            else
            {
                var460 = 0.021257622;
            }
        }
    }
    double var461;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 146.5)
        {
            var461 = 0.007685069;
        }
        else
        {
            var461 = 0.045899134;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var461 = 0.0022036836;
            }
            else
            {
                var461 = -0.04865597;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var461 = 0.042764883;
            }
            else
            {
                var461 = 0.0014992493;
            }
        }
    }
    double var462;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 142.5)
        {
            var462 = 0.007717509;
        }
        else
        {
            var462 = 0.045625046;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var462 = 0.0021849626;
            }
            else
            {
                var462 = -0.048553295;
            }
        }
        else
        {
            if (input[7] >= 1.9057617)
            {
                var462 = 0.010872013;
            }
            else
            {
                var462 = -0.0047529456;
            }
        }
    }
    double var463;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 137.5)
        {
            var463 = 0.007979848;
        }
        else
        {
            var463 = 0.045357376;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var463 = 0.002556741;
            }
            else
            {
                var463 = -0.048449572;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var463 = 0.042275254;
            }
            else
            {
                var463 = 0.00069622986;
            }
        }
    }
    double var464;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 137.5)
        {
            var464 = 0.0076715234;
        }
        else
        {
            var464 = 0.0450758;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var464 = 0.0022021204;
            }
            else
            {
                var464 = -0.04834397;
            }
        }
        else
        {
            if (input[14] >= 7.562256)
            {
                var464 = -0.0035729886;
            }
            else
            {
                var464 = 0.012298937;
            }
        }
    }
    double var465;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 137.5)
        {
            var465 = 0.007625816;
        }
        else
        {
            var465 = 0.044821978;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var465 = 0.0017285558;
            }
            else
            {
                var465 = -0.04823345;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var465 = 0.041788455;
            }
            else
            {
                var465 = 0.00022569236;
            }
        }
    }
    double var466;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 137.5)
        {
            var466 = 0.007706499;
        }
        else
        {
            var466 = 0.044585723;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var466 = 0.0021750415;
            }
            else
            {
                var466 = -0.04811928;
            }
        }
        else
        {
            if (input[7] >= 1.9057617)
            {
                var466 = 0.009808452;
            }
            else
            {
                var466 = -0.0051538134;
            }
        }
    }
    double var467;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 137.5)
        {
            var467 = 0.007722494;
        }
        else
        {
            var467 = 0.044321638;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var467 = 0.002564339;
            }
            else
            {
                var467 = -0.048001606;
            }
        }
        else
        {
            if (input[49] >= 94671.586)
            {
                var467 = -0.0016371269;
            }
            else
            {
                var467 = 0.018818915;
            }
        }
    }
    double var468;
    if (input[49] >= 96875.95)
    {
        var468 = 0.0435736;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var468 = 0.004878384;
            }
            else
            {
                var468 = -0.04788076;
            }
        }
        else
        {
            if (input[21] >= 478.85114)
            {
                var468 = -0.006663158;
            }
            else
            {
                var468 = 0.008145156;
            }
        }
    }
    double var469;
    if (input[49] >= 96875.95)
    {
        var469 = 0.043314952;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var469 = 0.004393211;
            }
            else
            {
                var469 = -0.047753613;
            }
        }
        else
        {
            if (input[14] >= 7.562256)
            {
                var469 = -0.004550501;
            }
            else
            {
                var469 = 0.010849927;
            }
        }
    }
    double var470;
    if (input[49] >= 96875.95)
    {
        var470 = 0.043071058;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var470 = 0.0044215294;
            }
            else
            {
                var470 = -0.047622472;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var470 = 0.04117795;
            }
            else
            {
                var470 = -0.0005670853;
            }
        }
    }
    double var471;
    if (input[49] >= 96875.95)
    {
        var471 = 0.042782824;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var471 = 0.0038438018;
            }
            else
            {
                var471 = -0.047488563;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var471 = 0.040732753;
            }
            else
            {
                var471 = -0.0006252595;
            }
        }
    }
    double var472;
    if (input[49] >= 96875.95)
    {
        var472 = 0.04250295;
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[42] >= 28.455)
            {
                var472 = -0.008401179;
            }
            else
            {
                var472 = 0.0070640086;
            }
        }
        else
        {
            if (input[56] >= 76.5)
            {
                var472 = -0.048317116;
            }
            else
            {
                var472 = 0.0087908935;
            }
        }
    }
    double var473;
    if (input[49] >= 96875.95)
    {
        var473 = 0.042250622;
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[14] >= 7.560791)
            {
                var473 = -0.0047403527;
            }
            else
            {
                var473 = 0.011051182;
            }
        }
        else
        {
            if (input[56] >= 76.5)
            {
                var473 = -0.048011865;
            }
            else
            {
                var473 = 0.008573509;
            }
        }
    }
    double var474;
    if (input[49] >= 96875.95)
    {
        var474 = 0.041835517;
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[7] >= 1.9057617)
            {
                var474 = 0.0084818145;
            }
            else
            {
                var474 = -0.006248358;
            }
        }
        else
        {
            if (input[56] >= 76.5)
            {
                var474 = -0.047775112;
            }
            else
            {
                var474 = 0.0078287525;
            }
        }
    }
    double var475;
    if (input[49] >= 96875.95)
    {
        var475 = 0.041564357;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var475 = 0.0047007683;
            }
            else
            {
                var475 = -0.04697631;
            }
        }
        else
        {
            if (input[49] >= 94671.586)
            {
                var475 = -0.002502754;
            }
            else
            {
                var475 = 0.017240962;
            }
        }
    }
    double var476;
    if (input[49] >= 96873.42)
    {
        if (input[56] >= 124.5)
        {
            var476 = 0.008457835;
        }
        else
        {
            var476 = 0.041747823;
        }
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[42] >= 28.455)
            {
                var476 = -0.008363456;
            }
            else
            {
                var476 = 0.006500475;
            }
        }
        else
        {
            if (input[0] >= 7.7922363)
            {
                var476 = 0.011144698;
            }
            else
            {
                var476 = -0.04893842;
            }
        }
    }
    double var477;
    if (input[49] >= 94724.9)
    {
        if (input[49] >= 96873.42)
        {
            if (input[56] >= 124.5)
            {
                var477 = 0.008233878;
            }
            else
            {
                var477 = 0.041408323;
            }
        }
        else
        {
            if (input[0] >= 7.482666)
            {
                var477 = -0.0050428654;
            }
            else
            {
                var477 = -0.036536966;
            }
        }
    }
    else
    {
        if (input[42] >= 28.455)
        {
            if (input[14] >= 7.3171387)
            {
                var477 = -0.013090176;
            }
            else
            {
                var477 = 0.029777309;
            }
        }
        else
        {
            if (input[42] >= 28.39)
            {
                var477 = 0.045947637;
            }
            else
            {
                var477 = 0.0047666254;
            }
        }
    }
    double var478;
    if (input[49] >= 94724.9)
    {
        if (input[49] >= 96870.875)
        {
            if (input[21] >= 1.2137405)
            {
                var478 = 0.035731427;
            }
            else
            {
                var478 = -0.010529338;
            }
        }
        else
        {
            if (input[42] >= 27.945)
            {
                var478 = -0.009312908;
            }
            else
            {
                var478 = -0.040528268;
            }
        }
    }
    else
    {
        if (input[42] >= 28.455)
        {
            if (input[14] >= 7.3171387)
            {
                var478 = -0.012021838;
            }
            else
            {
                var478 = 0.029470855;
            }
        }
        else
        {
            if (input[42] >= 28.39)
            {
                var478 = 0.044250492;
            }
            else
            {
                var478 = 0.0044023283;
            }
        }
    }
    double var479;
    if (input[49] >= 96875.95)
    {
        var479 = 0.040434588;
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[49] >= 96850.555)
            {
                var479 = 0.006139088;
            }
            else
            {
                var479 = -0.04644105;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var479 = 0.040203348;
            }
            else
            {
                var479 = -0.0003339323;
            }
        }
    }
    double var480;
    if (input[49] >= 96875.95)
    {
        var480 = 0.040064592;
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[7] >= 1.9057617)
            {
                var480 = 0.00829718;
            }
            else
            {
                var480 = -0.005675297;
            }
        }
        else
        {
            if (input[56] >= 76.5)
            {
                var480 = -0.04676509;
            }
            else
            {
                var480 = 0.010503135;
            }
        }
    }
    double var481;
    if (input[49] >= 96875.95)
    {
        var481 = 0.039743207;
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[14] >= 7.560791)
            {
                var481 = -0.004507033;
            }
            else
            {
                var481 = 0.00978249;
            }
        }
        else
        {
            if (input[0] >= 7.7922363)
            {
                var481 = 0.014571636;
            }
            else
            {
                var481 = -0.045101788;
            }
        }
    }
    double var482;
    if (input[49] >= 94671.586)
    {
        if (input[14] >= 7.675537)
        {
            if (input[42] >= 28.23)
            {
                var482 = 0.018140223;
            }
            else
            {
                var482 = -0.010307056;
            }
        }
        else
        {
            if (input[14] >= 7.634033)
            {
                var482 = -0.039567843;
            }
            else
            {
                var482 = -0.0053568254;
            }
        }
    }
    else
    {
        if (input[56] >= 139.0)
        {
            var482 = 0.055525996;
        }
        else
        {
            if (input[14] >= 7.5529785)
            {
                var482 = -0.019802412;
            }
            else
            {
                var482 = 0.040761873;
            }
        }
    }
    double var483;
    if (input[49] >= 96873.42)
    {
        if (input[7] >= 2.2592773)
        {
            var483 = 0.009183825;
        }
        else
        {
            var483 = 0.039962776;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[0] >= 7.7922363)
            {
                var483 = 0.010502993;
            }
            else
            {
                var483 = -0.04609577;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var483 = 0.039480127;
            }
            else
            {
                var483 = -0.0005998779;
            }
        }
    }
    double var484;
    if (input[49] >= 96875.95)
    {
        var484 = 0.039111864;
    }
    else
    {
        if (input[42] >= 27.314999)
        {
            if (input[7] >= 1.9060059)
            {
                var484 = 0.0064629125;
            }
            else
            {
                var484 = -0.0064259022;
            }
        }
        else
        {
            var484 = -0.042565774;
        }
    }
    double var485;
    if (input[49] >= 94671.586)
    {
        if (input[14] >= 7.675537)
        {
            if (input[42] >= 28.23)
            {
                var485 = 0.017696237;
            }
            else
            {
                var485 = -0.009779049;
            }
        }
        else
        {
            if (input[14] >= 7.634033)
            {
                var485 = -0.037249066;
            }
            else
            {
                var485 = -0.004488571;
            }
        }
    }
    else
    {
        if (input[56] >= 139.0)
        {
            var485 = 0.05451873;
        }
        else
        {
            if (input[14] >= 7.5529785)
            {
                var485 = -0.01835618;
            }
            else
            {
                var485 = 0.039766397;
            }
        }
    }
    double var486;
    if (input[49] >= 96875.95)
    {
        var486 = 0.038837604;
    }
    else
    {
        if (input[42] >= 27.314999)
        {
            if (input[49] >= 94671.586)
            {
                var486 = -0.0026148788;
            }
            else
            {
                var486 = 0.015293777;
            }
        }
        else
        {
            var486 = -0.042175706;
        }
    }
    double var487;
    if (input[49] >= 96875.95)
    {
        var487 = 0.038439345;
    }
    else
    {
        if (input[42] >= 27.285)
        {
            if (input[7] >= 1.9060059)
            {
                var487 = 0.006345935;
            }
            else
            {
                var487 = -0.0058797854;
            }
        }
        else
        {
            var487 = -0.042609613;
        }
    }
    double var488;
    if (input[49] >= 96875.95)
    {
        var488 = 0.038143683;
    }
    else
    {
        if (input[42] >= 27.285)
        {
            if (input[49] >= 94671.586)
            {
                var488 = -0.002501737;
            }
            else
            {
                var488 = 0.014774797;
            }
        }
        else
        {
            var488 = -0.04230601;
        }
    }
    double var489;
    if (input[49] >= 96875.95)
    {
        var489 = 0.037761636;
    }
    else
    {
        if (input[42] >= 27.314999)
        {
            if (input[21] >= 499.75952)
            {
                var489 = 0.03837443;
            }
            else
            {
                var489 = -0.0008771247;
            }
        }
        else
        {
            var489 = -0.041223112;
        }
    }
    double var490;
    if (input[49] >= 94724.9)
    {
        if (input[49] >= 96850.555)
        {
            if (input[42] >= 27.465)
            {
                var490 = -0.020964447;
            }
            else
            {
                var490 = 0.031935308;
            }
        }
        else
        {
            if (input[42] >= 27.945)
            {
                var490 = -0.0073625627;
            }
            else
            {
                var490 = -0.046754334;
            }
        }
    }
    else
    {
        if (input[42] >= 28.455)
        {
            if (input[14] >= 7.3171387)
            {
                var490 = -0.011301308;
            }
            else
            {
                var490 = 0.027534997;
            }
        }
        else
        {
            if (input[42] >= 28.39)
            {
                var490 = 0.040905353;
            }
            else
            {
                var490 = 0.004635127;
            }
        }
    }
    double var491;
    if (input[49] >= 96875.95)
    {
        var491 = 0.037086967;
    }
    else
    {
        if (input[42] >= 27.285)
        {
            if (input[7] >= 1.9060059)
            {
                var491 = 0.006036582;
            }
            else
            {
                var491 = -0.005465639;
            }
        }
        else
        {
            var491 = -0.041371547;
        }
    }
    double var492;
    if (input[49] >= 94671.586)
    {
        if (input[14] >= 7.675537)
        {
            if (input[42] >= 28.23)
            {
                var492 = 0.017037733;
            }
            else
            {
                var492 = -0.0083950795;
            }
        }
        else
        {
            if (input[14] >= 7.634033)
            {
                var492 = -0.03555372;
            }
            else
            {
                var492 = -0.0041335234;
            }
        }
    }
    else
    {
        if (input[56] >= 139.0)
        {
            var492 = 0.05268064;
        }
        else
        {
            if (input[14] >= 7.5529785)
            {
                var492 = -0.017966526;
            }
            else
            {
                var492 = 0.03767874;
            }
        }
    }
    double var493;
    if (input[49] >= 96873.42)
    {
        if (input[35] >= 485.187)
        {
            var493 = 0.008994169;
        }
        else
        {
            var493 = 0.037185017;
        }
    }
    else
    {
        if (input[42] >= 27.945)
        {
            if (input[42] >= 28.455)
            {
                var493 = -0.006749455;
            }
            else
            {
                var493 = 0.005483853;
            }
        }
        else
        {
            if (input[0] >= 7.7922363)
            {
                var493 = 0.015306922;
            }
            else
            {
                var493 = -0.046384376;
            }
        }
    }
    double var494;
    if (input[49] >= 96875.95)
    {
        var494 = 0.036566354;
    }
    else
    {
        if (input[42] >= 27.285)
        {
            if (input[21] >= 499.75952)
            {
                var494 = 0.037190113;
            }
            else
            {
                var494 = -0.0011753755;
            }
        }
        else
        {
            var494 = -0.040688068;
        }
    }
    double var495;
    if (input[49] >= 94671.586)
    {
        if (input[14] >= 7.675537)
        {
            if (input[42] >= 28.23)
            {
                var495 = 0.016198764;
            }
            else
            {
                var495 = -0.007958995;
            }
        }
        else
        {
            if (input[49] >= 94684.28)
            {
                var495 = -0.002380952;
            }
            else
            {
                var495 = -0.028021196;
            }
        }
    }
    else
    {
        if (input[56] >= 139.0)
        {
            var495 = 0.051903475;
        }
        else
        {
            if (input[14] >= 7.5529785)
            {
                var495 = -0.01674092;
            }
            else
            {
                var495 = 0.03630401;
            }
        }
    }
    double var496;
    if (input[7] >= 1.9060059)
    {
        if (input[7] >= 2.013916)
        {
            if (input[28] >= 470.91223)
            {
                var496 = -0.030050755;
            }
            else
            {
                var496 = 0.0037854302;
            }
        }
        else
        {
            if (input[42] >= 28.23)
            {
                var496 = 0.04334138;
            }
            else
            {
                var496 = 0.00020570544;
            }
        }
    }
    else
    {
        if (input[56] >= 120.5)
        {
            if (input[42] >= 28.05)
            {
                var496 = 0.008591702;
            }
            else
            {
                var496 = -0.036965802;
            }
        }
        else
        {
            if (input[49] >= 94684.28)
            {
                var496 = -0.0023340154;
            }
            else
            {
                var496 = -0.03748224;
            }
        }
    }
    double var497;
    if (input[49] >= 96873.42)
    {
        if (input[35] >= 484.48474)
        {
            var497 = 0.009438558;
        }
        else
        {
            var497 = 0.036437254;
        }
    }
    else
    {
        if (input[49] >= 94798.516)
        {
            if (input[0] >= 7.7922363)
            {
                var497 = 0.011438756;
            }
            else
            {
                var497 = -0.044065695;
            }
        }
        else
        {
            if (input[42] >= 28.555)
            {
                var497 = 0.038251366;
            }
            else
            {
                var497 = -0.0004990142;
            }
        }
    }
    double var498;
    if (input[49] >= 94671.586)
    {
        if (input[14] >= 7.675537)
        {
            if (input[49] >= 94676.66)
            {
                var498 = 0.010662565;
            }
            else
            {
                var498 = -0.028012618;
            }
        }
        else
        {
            if (input[14] >= 7.634033)
            {
                var498 = -0.03371607;
            }
            else
            {
                var498 = -0.003729889;
            }
        }
    }
    else
    {
        if (input[56] >= 139.0)
        {
            var498 = 0.05074984;
        }
        else
        {
            if (input[14] >= 7.5529785)
            {
                var498 = -0.015125051;
            }
            else
            {
                var498 = 0.03541808;
            }
        }
    }
    double var499;
    if (input[21] >= 499.75952)
    {
        if (input[0] >= 7.5532227)
        {
            var499 = 0.049938735;
        }
        else
        {
            var499 = 0.000116279385;
        }
    }
    else
    {
        if (input[21] >= 22.767174)
        {
            if (input[49] >= 94671.586)
            {
                var499 = -0.010216343;
            }
            else
            {
                var499 = 0.014312836;
            }
        }
        else
        {
            if (input[21] >= 4.59542)
            {
                var499 = 0.013026014;
            }
            else
            {
                var499 = -0.009480496;
            }
        }
    }
    double var500;
    if (input[49] >= 96875.95)
    {
        var500 = 0.035821535;
    }
    else
    {
        if (input[42] >= 27.285)
        {
            if (input[21] >= 499.75952)
            {
                var500 = 0.035270505;
            }
            else
            {
                var500 = -0.0010356286;
            }
        }
        else
        {
            var500 = -0.039890584;
        }
    }
    softmax((double[]){0.5 + (var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10 + var11 + var12 + var13 + var14 + var15 + var16 + var17 + var18 + var19 + var20 + var21 + var22 + var23 + var24 + var25 + var26 + var27 + var28 + var29 + var30 + var31 + var32 + var33 + var34 + var35 + var36 + var37 + var38 + var39 + var40 + var41 + var42 + var43 + var44 + var45 + var46 + var47 + var48 + var49 + var50 + var51 + var52 + var53 + var54 + var55 + var56 + var57 + var58 + var59 + var60 + var61 + var62 + var63 + var64 + var65 + var66 + var67 + var68 + var69 + var70 + var71 + var72 + var73 + var74 + var75 + var76 + var77 + var78 + var79 + var80 + var81 + var82 + var83 + var84 + var85 + var86 + var87 + var88 + var89 + var90 + var91 + var92 + var93 + var94 + var95 + var96 + var97 + var98 + var99 + var100), 0.5 + (var101 + var102 + var103 + var104 + var105 + var106 + var107 + var108 + var109 + var110 + var111 + var112 + var113 + var114 + var115 + var116 + var117 + var118 + var119 + var120 + var121 + var122 + var123 + var124 + var125 + var126 + var127 + var128 + var129 + var130 + var131 + var132 + var133 + var134 + var135 + var136 + var137 + var138 + var139 + var140 + var141 + var142 + var143 + var144 + var145 + var146 + var147 + var148 + var149 + var150 + var151 + var152 + var153 + var154 + var155 + var156 + var157 + var158 + var159 + var160 + var161 + var162 + var163 + var164 + var165 + var166 + var167 + var168 + var169 + var170 + var171 + var172 + var173 + var174 + var175 + var176 + var177 + var178 + var179 + var180 + var181 + var182 + var183 + var184 + var185 + var186 + var187 + var188 + var189 + var190 + var191 + var192 + var193 + var194 + var195 + var196 + var197 + var198 + var199 + var200), 0.5 + (var201 + var202 + var203 + var204 + var205 + var206 + var207 + var208 + var209 + var210 + var211 + var212 + var213 + var214 + var215 + var216 + var217 + var218 + var219 + var220 + var221 + var222 + var223 + var224 + var225 + var226 + var227 + var228 + var229 + var230 + var231 + var232 + var233 + var234 + var235 + var236 + var237 + var238 + var239 + var240 + var241 + var242 + var243 + var244 + var245 + var246 + var247 + var248 + var249 + var250 + var251 + var252 + var253 + var254 + var255 + var256 + var257 + var258 + var259 + var260 + var261 + var262 + var263 + var264 + var265 + var266 + var267 + var268 + var269 + var270 + var271 + var272 + var273 + var274 + var275 + var276 + var277 + var278 + var279 + var280 + var281 + var282 + var283 + var284 + var285 + var286 + var287 + var288 + var289 + var290 + var291 + var292 + var293 + var294 + var295 + var296 + var297 + var298 + var299 + var300), 0.5 + (var301 + var302 + var303 + var304 + var305 + var306 + var307 + var308 + var309 + var310 + var311 + var312 + var313 + var314 + var315 + var316 + var317 + var318 + var319 + var320 + var321 + var322 + var323 + var324 + var325 + var326 + var327 + var328 + var329 + var330 + var331 + var332 + var333 + var334 + var335 + var336 + var337 + var338 + var339 + var340 + var341 + var342 + var343 + var344 + var345 + var346 + var347 + var348 + var349 + var350 + var351 + var352 + var353 + var354 + var355 + var356 + var357 + var358 + var359 + var360 + var361 + var362 + var363 + var364 + var365 + var366 + var367 + var368 + var369 + var370 + var371 + var372 + var373 + var374 + var375 + var376 + var377 + var378 + var379 + var380 + var381 + var382 + var383 + var384 + var385 + var386 + var387 + var388 + var389 + var390 + var391 + var392 + var393 + var394 + var395 + var396 + var397 + var398 + var399 + var400), 0.5 + (var401 + var402 + var403 + var404 + var405 + var406 + var407 + var408 + var409 + var410 + var411 + var412 + var413 + var414 + var415 + var416 + var417 + var418 + var419 + var420 + var421 + var422 + var423 + var424 + var425 + var426 + var427 + var428 + var429 + var430 + var431 + var432 + var433 + var434 + var435 + var436 + var437 + var438 + var439 + var440 + var441 + var442 + var443 + var444 + var445 + var446 + var447 + var448 + var449 + var450 + var451 + var452 + var453 + var454 + var455 + var456 + var457 + var458 + var459 + var460 + var461 + var462 + var463 + var464 + var465 + var466 + var467 + var468 + var469 + var470 + var471 + var472 + var473 + var474 + var475 + var476 + var477 + var478 + var479 + var480 + var481 + var482 + var483 + var484 + var485 + var486 + var487 + var488 + var489 + var490 + var491 + var492 + var493 + var494 + var495 + var496 + var497 + var498 + var499 + var500)}, 5, var0);
    memcpy(output, var0, 5 * sizeof(double));
}
