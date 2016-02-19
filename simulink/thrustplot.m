%
%Thrust (kgf)	Pulse Width (us)
%X Y
map = [
-1.768181818	1100
-1.640909091	1110
-1.577272727	1120
-1.527272727	1130
-1.440909091	1140
-1.4	1150
-1.322727273	1160
-1.259090909	1170
-1.209090909	1180
-1.163636364	1190
-1.104545455	1200
-1.040909091	1210
-0.990909091	1220
-0.927272727	1230
-0.854545455	1240
-0.790909091	1250
-0.754545455	1260
-0.704545455	1270
-0.668181818	1280
-0.622727273	1290
-0.581818182	1300
-0.531818182	1310
-0.472727273	1320
-0.427272727	1330
-0.4	1340
-0.368181818	1350
-0.327272727	1360
-0.272727273	1370
-0.231818182	1380
-0.2	1390
-0.168181818	1400
-0.140909091	1410
-0.104545455	1420
-0.072727273	1430
-0.05	1440
-0.031818182	1450
-0.013636364	1460
-0.009090909	1470
0	1480
0	1500
0	1510
0	1520
0.009090909	1530
0.036363636	1540
0.063636364	1550
0.104545455	1560
0.145454545	1570
0.195454545	1580
0.254545455	1590
0.309090909	1600
0.368181818	1610
0.431818182	1620
0.481818182	1630
0.545454545	1640
0.613636364	1650
0.686363636	1660
0.736363636	1670
0.804545455	1680
0.881818182	1690
0.963636364	1700
1.059090909	1710
1.131818182	1720
1.186363636	1730
1.254545455	1740
1.304545455	1750
1.386363636	1760
1.490909091	1770
1.577272727	1780
1.654545455	1790
1.727272727	1800
1.822727273	1810
1.959090909	1820
2.045454545	1830
2.1	1840
2.181818182	1850
2.263636364	1860
2.322727273	1870
2.418181818	1880
2.486363636	1890
2.518181818	1900];

% thrust@16V rpm power16V curtent16V voltage pwm thrust(kgf)12V efficiency(g/W)
mapt20016 = [...
-9	3200	344.48	21.53	14.98	1100	-4.082336184920758	11.850720462496392
-8.9	2767	341.92	21.37	15.25	1110	-4.082336184920758	11.939448364882889
-8.7	3245	328.96	20.56	15.33	1120	-4.086872114015114	12.423614159822211
-8.44	3269	305.12	19.07	15.35	1130	-3.8283241556367993	12.546945974163606
-8.23	3269	289.12	18.07	15.35	1140	-3.7330696446553153	12.91183468682663
-7.98	3186	272.16	17.01	15.35	1150	-3.6196714172964053	13.299792097649929
-7.59	3141	254.56	15.91	15.35	1160	-3.442770182616506	13.524395751950447
-7.28	3084	238.72	14.92	15.35	1170	-3.3021563806914576	13.83275963761502
-7.02	3027	222.08	13.88	15.35	1180	-3.184222224238191	14.338176441994735
-6.74	2959	206.56	12.91	15.35	1190	-3.057216209596212	14.800620689369731
-6.41	2912	194.88	12.18	15.35	1200	-2.9075305494824506	14.919594363107814
-6.21	2847	182.08	11.38	15.35	1210	-2.816811967595323	15.470188749974312
-5.97	2776	167.36	10.46	15.35	1220	-2.707949669330769	16.18038760355383
-5.57	2732	152.48	9.53	15.35	1230	-2.5265125055565134	16.569468163408406
-5.21	2663	144.16	9.01	15.35	1240	-2.3632190581596833	16.393028982794696
-4.98	2581	130.88	8.18	15.35	1250	-2.2588926889894863	17.259265655482015
-4.8	2503	119.84	7.49	15.34	1260	-2.1772459652910707	18.167940297822685
-4.39	2467	106.72	6.67	15.35	1270	-1.9912728724224584	18.658853752084507
-4.15	2399	97.76	6.11	15.35	1280	-1.8824105741579051	19.255427313399192
-3.9	2296	87.68	5.48	15.35	1290	-1.7690123467989949	20.175779502725764
-3.62	2228	79.36	4.96	15.35	1300	-1.642006332157016	20.690603983833366
-3.29	2167	71.04	4.44	15.35	1310	-1.4923206720432547	21.006766216825092
-2.94	2074	62.24	3.89	15.34	1320	-1.3335631537407808	21.42614321562951
-2.74	1971	54.08	3.38	15.32	1330	-1.242844571853653	22.98159341445364
-2.47	1910	48.16	3.01	15.34	1340	-1.1203744863060303	23.263589831935846
-2.26	1827	41.92	2.62	15.32	1350	-1.0251199753245457	24.454197884650423
-2	1704	36.32	2.27	15.33	1360	-0.9071858188712795	24.97758311870263
-1.74	1732	30.72	1.92	15.33	1370	-0.7892516624180131	25.691785886003032
-1.53	1530	25.76	1.61	15.34	1380	-0.6939971514365288	26.940883207939784
-1.36	1421	21.76	1.36	15.33	1390	-0.6168863568324701	28.34955683972748
-1.15	1327	18.56	1.16	15.34	1400	-0.5216318458509857	28.10516410835052
-0.96	1215	15.2	0.95	15.34	1410	-0.4354491930582141	28.64797322751409
-9	3200	344.48	21.53	14.98	1100	-4.082336184920758	11.850720462496392
-8.9	2767	341.92	21.37	15.25	1110	-4.082336184920758	11.939448364882889
-8.7	3245	328.96	20.56	15.33	1120	-4.086872114015114	12.423614159822211
-8.44	3269	305.12	19.07	15.35	1130	-3.8283241556367993	12.546945974163606
-8.23	3269	289.12	18.07	15.35	1140	-3.7330696446553153	12.91183468682663
-7.98	3186	272.16	17.01	15.35	1150	-3.6196714172964053	13.299792097649929
-7.59	3141	254.56	15.91	15.35	1160	-3.442770182616506	13.524395751950447
-7.28	3084	238.72	14.92	15.35	1170	-3.3021563806914576	13.83275963761502
-7.02	3027	222.08	13.88	15.35	1180	-3.184222224238191	14.338176441994735
-6.74	2959	206.56	12.91	15.35	1190	-3.057216209596212	14.800620689369731
-6.41	2912	194.88	12.18	15.35	1200	-2.9075305494824506	14.919594363107814
-6.21	2847	182.08	11.38	15.35	1210	-2.816811967595323	15.470188749974312
-5.97	2776	167.36	10.46	15.35	1220	-2.707949669330769	16.18038760355383
-5.57	2732	152.48	9.53	15.35	1230	-2.5265125055565134	16.569468163408406
-5.21	2663	144.16	9.01	15.35	1240	-2.3632190581596833	16.393028982794696
-4.98	2581	130.88	8.18	15.35	1250	-2.2588926889894863	17.259265655482015
-4.8	2503	119.84	7.49	15.34	1260	-2.1772459652910707	18.167940297822685
-4.39	2467	106.72	6.67	15.35	1270	-1.9912728724224584	18.658853752084507
-4.15	2399	97.76	6.11	15.35	1280	-1.8824105741579051	19.255427313399192
-3.9	2296	87.68	5.48	15.35	1290	-1.7690123467989949	20.175779502725764
-3.62	2228	79.36	4.96	15.35	1300	-1.642006332157016	20.690603983833366
-3.29	2167	71.04	4.44	15.35	1310	-1.4923206720432547	21.006766216825092
-2.94	2074	62.24	3.89	15.34	1320	-1.3335631537407808	21.42614321562951
-2.74	1971	54.08	3.38	15.32	1330	-1.242844571853653	22.98159341445364
-2.47	1910	48.16	3.01	15.34	1340	-1.1203744863060303	23.263589831935846
-2.26	1827	41.92	2.62	15.32	1350	-1.0251199753245457	24.454197884650423
-2	1704	36.32	2.27	15.33	1360	-0.9071858188712795	24.97758311870263
-9	3200	344.48	21.53	14.98	1100	-4.082336184920758	11.850720462496392
-8.9	2767	341.92	21.37	15.25	1110	-4.082336184920758	11.939448364882889
-8.7	3245	328.96	20.56	15.33	1120	-4.086872114015114	12.423614159822211
-8.44	3269	305.12	19.07	15.35	1130	-3.8283241556367993	12.546945974163606
-8.23	3269	289.12	18.07	15.35	1140	-3.7330696446553153	12.91183468682663
-7.98	3186	272.16	17.01	15.35	1150	-3.6196714172964053	13.299792097649929
-7.59	3141	254.56	15.91	15.35	1160	-3.442770182616506	13.524395751950447
-7.28	3084	238.72	14.92	15.35	1170	-3.3021563806914576	13.83275963761502
-7.02	3027	222.08	13.88	15.35	1180	-3.184222224238191	14.338176441994735
-6.74	2959	206.56	12.91	15.35	1190	-3.057216209596212	14.800620689369731
-6.41	2912	194.88	12.18	15.35	1200	-2.9075305494824506	14.919594363107814
-6.21	2847	182.08	11.38	15.35	1210	-2.816811967595323	15.470188749974312
-5.97	2776	167.36	10.46	15.35	1220	-2.707949669330769	16.18038760355383
-5.57	2732	152.48	9.53	15.35	1230	-2.5265125055565134	16.569468163408406
-5.21	2663	144.16	9.01	15.35	1240	-2.3632190581596833	16.393028982794696
-4.98	2581	130.88	8.18	15.35	1250	-2.2588926889894863	17.259265655482015
-4.8	2503	119.84	7.49	15.34	1260	-2.1772459652910707	18.167940297822685
-4.39	2467	106.72	6.67	15.35	1270	-1.9912728724224584	18.658853752084507
-4.15	2399	97.76	6.11	15.35	1280	-1.8824105741579051	19.255427313399192
-3.9	2296	87.68	5.48	15.35	1290	-1.7690123467989949	20.175779502725764
-3.62	2228	79.36	4.96	15.35	1300	-1.642006332157016	20.690603983833366
-3.29	2167	71.04	4.44	15.35	1310	-1.4923206720432547	21.006766216825092];

% thrust@12V rpm power16V curtent16V voltage pwm thrust(kgf)12V efficiency(g/W)
mapt20012 = [...
-6.62	2960	182.2	15.4	11.83	1100	-3.002785060463935	16.48070834502709
-6.58	2870	181.03	15.19	11.92	1110	-2.9846413440865094	16.486998531108156
-6.34	2837	169.05	14.25	11.86	1120	-2.875779045821956	17.011411096255284
-6.09	2784	160.31	13.48	11.89	1130	-2.762380818463046	17.231494095583844
-5.8	2750	146.97	12.38	11.87	1140	-2.6308388747267104	17.900516259962647
-5.59	2693	138.13	11.66	11.85	1150	-2.535584363745226	18.35650737526407
-5.23	2655	129.74	10.95	11.85	1160	-2.372290916348396	18.284961587393216
-5.15	2595	122.62	10.32	11.88	1170	-2.336003483593545	19.05075422927373
-4.98	2556	115.86	9.72	11.92	1180	-2.2588926889894863	19.49674338848167
-4.77	2494	107.18	9	11.91	1190	-2.1636381780080014	20.186958182571388
-4.34	2423	98.66	8.31	11.88	1200	-1.9685932269506765	19.95330657764724
-4.01	2390	90.31	7.6	11.88	1210	-1.8189075668369152	20.140710517516503
-3.86	2348	82.64	6.94	11.9	1220	-1.7508686304215693	21.18669688312644
-3.72	2286	77.22	6.47	11.93	1230	-1.68736562310058	21.851406670559182
-3.48	2227	71.44	5.97	11.96	1240	-1.5785033248360263	22.095511265901823
-3.18	2168	64.4	5.4	11.93	1250	-1.4424254520053346	22.397910745424447
-3.11	2074	60.03	5.03	11.94	1260	-1.4106739483448396	23.499482731048467
-2.91	2021	54.96	4.6	11.95	1270	-1.3199553664577117	24.016655139332457
-2.69	1960	49.63	4.16	11.94	1280	-1.2201649263818708	24.58522922389423
-2.53	1948	44.93	3.78	11.89	1290	-1.1475900608721685	25.541732937283967
-2.4	2102	41.12	3.46	11.9	1300	-1.0886229826455354	26.474294325037338
-2.23	1772	36.64	3.08	11.91	1310	-1.0115121880414766	27.606773691088335
-1.97	1687	31.96	2.68	11.93	1320	-0.8935780315882103	27.959262565338243
-1.76	1617	28.21	2.36	11.95	1330	-0.798323520606726	28.299309486236297
-1.66	1915	24.9	2.08	11.96	1340	-0.7529642296631619	30.239527295709312
-1.48	1501	21.47	1.8	11.91	1350	-0.6713175059647468	31.26769939286199
-1.32	1369	18.54	1.56	11.9	1360	-0.5987426404550444	32.29464080124296
-1.12	1293	15.79	1.33	11.89	1370	-0.5080240585679165	32.17378458314861
-0.96	1208	13.49	1.13	11.91	1380	-0.4354491930582141	32.279406453537
-0.83	1114	11.48	0.96	11.92	1390	-0.37648211483158095	32.79460930588684
-0.71	1028	9.58	0.8	11.92	1400	-0.3220509656993042	33.61701103333029
-0.6	933	8.03	0.67	11.92	1410	-0.27215574566138384	33.89237181337283
-0.47	813	6.51	0.55	11.93	1420	-0.21318866743475068	32.74787518198935
-0.38	626	5.26	0.44	11.94	1430	-0.1723653055855431	32.76906950295496
-0.27	464	4.19	0.35	11.94	1440	-0.12247008554762275	29.22913736220113
-0.19	331	3.33	0.28	11.94	1450	-0.08618265279277156	25.88067651434581
-0.13	672	2.7	0.23	11.95	1460	-0.05896707822663317	21.83965860245673
-0.08	388	2.17	0.18	11.94	1470	-0.03628743275485118	16.722319241866906
0	34	0.89	0.07	11.95	1480	0	0
0	0	0.58	0.05	11.96	1490	0	0
0	0	0.51	0.04	11.96	1500	0	0
0	0	0.6	0.05	11.96	1510	0	0
0	24	0.95	0.08	11.96	1520	0	0
0.11	368	2.14	0.18	11.95	1530	0.04989522003792037	23.315523382205782
0.19	467	2.73	0.23	11.95	1540	0.08618265279277156	31.568737286729505
0.28	303	3.45	0.29	11.94	1550	0.12700601464197914	36.813337577385255
0.39	460	4.33	0.36	11.94	1560	0.17690123467989952	40.85478860967656
0.51	568	5.51	0.46	11.94	1570	0.23133238381217627	41.98409869549479
0.63	763	6.9	0.58	11.93	1580	0.28576353294445306	41.41500477455841
0.79	915	8.43	0.71	11.93	1590	0.35833839845415544	42.50752057581915
0.93	1012	10.12	0.85	11.93	1600	0.421841405775145	41.683933376990616
1.04	1165	11.87	1	11.91	1610	0.47173662581306536	39.74192298340905
1.24	1174	14.13	1.19	11.9	1620	0.5624552077001933	39.80574718331163
1.4	1259	16.66	1.4	11.89	1630	0.6350300732098956	38.117051213078966
1.46	1353	19.04	1.6	11.87	1640	0.662245647776034	34.78180923193456
1.65	1439	21.61	1.82	11.88	1650	0.7484283005688055	34.63342436690447
1.91	1507	24.72	2.08	11.88	1660	0.8663624570220718	35.0470249604398
2.14	1576	28.29	2.38	11.9	1670	0.9706888261922691	34.31208293362563
2.3	1670	32.41	2.72	11.92	1680	1.0432636917019713	32.18956160758937
2.53	1747	36.17	3.04	11.89	1690	1.1475900608721685	31.72767655162202
2.84	1807	40.48	3.41	11.88	1700	1.2882038627972168	31.8232179544767
3.1	1851	46.03	3.87	11.9	1710	1.4061380192504833	30.54829500870048
3.33	1943	50.54	4.23	11.94	1720	1.5104643884206803	29.886513423440448
3.55	2012	54.9	4.61	11.92	1730	1.610254828496521	29.330689043652477
3.85	2074	60.49	5.08	11.9	1740	1.746332701327213	28.869775191390527
4.09	2141	65.93	5.56	11.87	1750	1.8551949995917665	28.13885939013751
4.34	2183	72.24	6.09	11.86	1760	1.9685932269506765	27.25073680717991
4.69	2227	78.85	6.65	11.86	1770	2.1273507452531506	26.97971775844199
4.8	2314	84.28	7.09	11.89	1780	2.1772459652910707	25.833483214179765
5.02	2365	90.69	7.65	11.86	1790	2.2770364053669114	25.107910523397415
5.15	2441	97.09	8.15	11.91	1800	2.336003483593545	24.0601862559846
5.55	2510	106.05	8.92	11.9	1810	2.5174406473678004	23.738242785174922
5.88	2554	114	9.6	11.87	1820	2.6671263074815617	23.39584480246984
6.07	2614	119.88	10.1	11.87	1830	2.7533089602743335	22.96720854416361
6.48	2648	129.97	10.95	11.87	1840	2.9392820531429455	22.61508081205621
6.52	2724	137.43	11.57	11.88	1850	2.9574257695203707	21.519506436152007
6.58	2802	145.51	12.18	11.94	1860	2.9846413440865094	20.511589197213315
6.95	2874	156.08	13.06	11.95	1870	3.1524707205776963	20.19778780482891
7.36	2915	166.98	13.96	11.96	1880	3.338443813446309	19.993075897989634
7.66	2956	176.44	14.79	11.93	1890	3.4745216862770003	19.69236956629449
7.79	2998	178.22	14.91	11.95	1900	3.5334887645036335	19.82655574292242];



%P = [56.6703763943 298.3976377754 1453.7943326152];
P = [-1.3536   -0.4257    2.5444    0.8196    0.9102    0.0111];
thrust = polyval(P,(map(:,2) - 1500)/400);

figure(1)
plot((map(:,2)-1500)/400, map(:,1),'b', (map(:,2)-1500)/400,thrust,'--r')
ylabel('Thrust [kgf]')
xlabel('Input [%]')

polystring = 'f(u)=';
for i = 1:size(P,2)
    exponent = size(P,2)-i;

    if ((exponent == (size(P,2)-1)) && (exponent > 0))
        new_string = strcat(num2str(P(i)),'*u^',int2str(exponent));
    elseif exponent <= 0
        if P(i) > 0
         tecken = strcat('+',num2str(P(i)));
        else
            tecken = num2str(P(i));
        end
        new_string = tecken;
    elseif exponent ==1
        if P(i) > 0
         tecken = strcat('+',num2str(P(i)));
        else
            tecken = num2str(P(i));
        end
        new_string = strcat(tecken,'*u');
    else
        if P(i) >= 0
            tecken = strcat('+',num2str(P(i)));
        else
            tecken = num2str(P(i));
        end
        new_string = strcat(tecken, '*u^',int2str(exponent));
    end
    polystring = strcat(polystring,new_string);
end
legend('Measured',polystring ,'location','NorthWest')
%print -f1 -depsc2 thrusterplot.eps
%print -f1 -dpdf thrusterplot.pdf


% latex_map = [];
% for i = 1:size(map,1)
%     temp = strcat(num2str(map(i,1)), ' & ', num2str(map(i,2)), ' \\');
%     disp(temp)
%     latex_map{i} = temp;  
% end
