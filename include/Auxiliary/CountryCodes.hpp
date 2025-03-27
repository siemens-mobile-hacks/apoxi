/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------
    ISO 3166 Country Codes
    Do not manualy modify this file.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CountryCodes_hpp)
#define Apoxi_CountryCodes_hpp

#if defined(APOXI_LITTLE_ENDIAN)
#define ApoxiMakeCountryCode(a,b)   ((((UINT) b) << 8U) | ((UINT) a))
#else
#define ApoxiMakeCountryCode(a,b)   ((((UINT) a) << 8U) | ((UINT) b))
#endif

enum CountryCodes {
    CountryAF = ApoxiMakeCountryCode(A,F),  // AFGHANISTAN
    CountryAL = ApoxiMakeCountryCode(A,L),  // ALBANIA
    CountryDZ = ApoxiMakeCountryCode(D,Z),  // ALGERIA
    CountryAS = ApoxiMakeCountryCode(A,S),  // AMERICAN SAMOA
    CountryAD = ApoxiMakeCountryCode(A,D),  // ANDORRA
    CountryAO = ApoxiMakeCountryCode(A,O),  // ANGOLA
    CountryAI = ApoxiMakeCountryCode(A,I),  // ANGUILLA
    CountryAQ = ApoxiMakeCountryCode(A,Q),  // ANTARCTICA
    CountryAG = ApoxiMakeCountryCode(A,G),  // ANTIGUA AND BARBUDA
    CountryAR = ApoxiMakeCountryCode(A,R),  // ARGENTINA
    CountryAM = ApoxiMakeCountryCode(A,M),  // ARMENIA
    CountryAW = ApoxiMakeCountryCode(A,W),  // ARUBA
    CountryAU = ApoxiMakeCountryCode(A,U),  // AUSTRALIA
    CountryAT = ApoxiMakeCountryCode(A,T),  // AUSTRIA
    CountryAZ = ApoxiMakeCountryCode(A,Z),  // AZERBAIJAN
    CountryBS = ApoxiMakeCountryCode(B,S),  // BAHAMAS
    CountryBH = ApoxiMakeCountryCode(B,H),  // BAHRAIN
    CountryBD = ApoxiMakeCountryCode(B,D),  // BANGLADESH
    CountryBB = ApoxiMakeCountryCode(B,B),  // BARBADOS
    CountryBY = ApoxiMakeCountryCode(B,Y),  // BELARUS
    CountryBE = ApoxiMakeCountryCode(B,E),  // BELGIUM
    CountryBZ = ApoxiMakeCountryCode(B,Z),  // BELIZE
    CountryBJ = ApoxiMakeCountryCode(B,J),  // BENIN
    CountryBM = ApoxiMakeCountryCode(B,M),  // BERMUDA
    CountryBT = ApoxiMakeCountryCode(B,T),  // BHUTAN
    CountryBO = ApoxiMakeCountryCode(B,O),  // BOLIVIA
    CountryBA = ApoxiMakeCountryCode(B,A),  // BOSNIA AND HERZEGOWINA
    CountryBW = ApoxiMakeCountryCode(B,W),  // BOTSWANA
    CountryBV = ApoxiMakeCountryCode(B,V),  // BOUVET ISLAND
    CountryBR = ApoxiMakeCountryCode(B,R),  // BRAZIL
    CountryIO = ApoxiMakeCountryCode(I,O),  // BRITISH INDIAN OCEAN TERRITORY
    CountryBN = ApoxiMakeCountryCode(B,N),  // BRUNEI DARUSSALAM
    CountryBG = ApoxiMakeCountryCode(B,G),  // BULGARIA
    CountryBF = ApoxiMakeCountryCode(B,F),  // BURKINA FASO
    CountryBI = ApoxiMakeCountryCode(B,I),  // BURUNDI
    CountryKH = ApoxiMakeCountryCode(K,H),  // CAMBODIA
    CountryCM = ApoxiMakeCountryCode(C,M),  // CAMEROON
    CountryCA = ApoxiMakeCountryCode(C,A),  // CANADA
    CountryCV = ApoxiMakeCountryCode(C,V),  // CAPE VERDE
    CountryKY = ApoxiMakeCountryCode(K,Y),  // CAYMAN ISLANDS
    CountryCF = ApoxiMakeCountryCode(C,F),  // CENTRAL AFRICAN REPUBLIC
    CountryTD = ApoxiMakeCountryCode(T,D),  // CHAD
    CountryCL = ApoxiMakeCountryCode(C,L),  // CHILE
    CountryCN = ApoxiMakeCountryCode(C,N),  // CHINA
    CountryCX = ApoxiMakeCountryCode(C,X),  // CHRISTMAS ISLAND
    CountryCC = ApoxiMakeCountryCode(C,C),  // COCOS (KEELING) ISLANDS
    CountryCO = ApoxiMakeCountryCode(C,O),  // COLOMBIA
    CountryKM = ApoxiMakeCountryCode(K,M),  // COMOROS
    CountryCG = ApoxiMakeCountryCode(C,G),  // CONGO
    CountryCK = ApoxiMakeCountryCode(C,K),  // COOK ISLANDS
    CountryCR = ApoxiMakeCountryCode(C,R),  // COSTA RICA
    CountryCI = ApoxiMakeCountryCode(C,I),  // COTE D'IVOIRE
    CountryHR = ApoxiMakeCountryCode(H,R),  // CROATIA (local name: Hrvatska)
    CountryCU = ApoxiMakeCountryCode(C,U),  // CUBA
    CountryCY = ApoxiMakeCountryCode(C,Y),  // CYPRUS
    CountryCZ = ApoxiMakeCountryCode(C,Z),  // CZECH REPUBLIC
    CountryDK = ApoxiMakeCountryCode(D,K),  // DENMARK
    CountryDJ = ApoxiMakeCountryCode(D,J),  // DJIBOUTI
    CountryDM = ApoxiMakeCountryCode(D,M),  // DOMINICA
    CountryDO = ApoxiMakeCountryCode(D,O),  // DOMINICAN REPUBLIC
    CountryTP = ApoxiMakeCountryCode(T,P),  // EAST TIMOR
    CountryEC = ApoxiMakeCountryCode(E,C),  // ECUADOR
    CountryEG = ApoxiMakeCountryCode(E,G),  // EGYPT
    CountrySV = ApoxiMakeCountryCode(S,V),  // EL SALVADOR
    CountryGQ = ApoxiMakeCountryCode(G,Q),  // EQUATORIAL GUINEA
    CountryER = ApoxiMakeCountryCode(E,R),  // ERITREA
    CountryEE = ApoxiMakeCountryCode(E,E),  // ESTONIA
    CountryET = ApoxiMakeCountryCode(E,T),  // ETHIOPIA
    CountryFK = ApoxiMakeCountryCode(F,K),  // FALKLAND ISLANDS (MALVINAS)
    CountryFO = ApoxiMakeCountryCode(F,O),  // FAROE ISLANDS
    CountryFJ = ApoxiMakeCountryCode(F,J),  // FIJI
    CountryFI = ApoxiMakeCountryCode(F,I),  // FINLAND
    CountryFR = ApoxiMakeCountryCode(F,R),  // FRANCE
    CountryFX = ApoxiMakeCountryCode(F,X),  // FRANCE, METROPOLITAN
    CountryGF = ApoxiMakeCountryCode(G,F),  // FRENCH GUIANA
    CountryPF = ApoxiMakeCountryCode(P,F),  // FRENCH POLYNESIA
    CountryTF = ApoxiMakeCountryCode(T,F),  // FRENCH SOUTHERN TERRITORIES
    CountryGA = ApoxiMakeCountryCode(G,A),  // GABON
    CountryGM = ApoxiMakeCountryCode(G,M),  // GAMBIA
    CountryGE = ApoxiMakeCountryCode(G,E),  // GEORGIA
    CountryDE = ApoxiMakeCountryCode(D,E),  // GERMANY
    CountryGH = ApoxiMakeCountryCode(G,H),  // GHANA
    CountryGI = ApoxiMakeCountryCode(G,I),  // GIBRALTAR
    CountryGR = ApoxiMakeCountryCode(G,R),  // GREECE
    CountryGL = ApoxiMakeCountryCode(G,L),  // GREENLAND
    CountryGD = ApoxiMakeCountryCode(G,D),  // GRENADA
    CountryGP = ApoxiMakeCountryCode(G,P),  // GUADELOUPE
    CountryGU = ApoxiMakeCountryCode(G,U),  // GUAM
    CountryGT = ApoxiMakeCountryCode(G,T),  // GUATEMALA
    CountryGN = ApoxiMakeCountryCode(G,N),  // GUINEA
    CountryGW = ApoxiMakeCountryCode(G,W),  // GUINEA-BISSAU
    CountryGY = ApoxiMakeCountryCode(G,Y),  // GUYANA
    CountryHT = ApoxiMakeCountryCode(H,T),  // HAITI
    CountryHM = ApoxiMakeCountryCode(H,M),  // HEARD AND MC DONALD ISLANDS
    CountryHN = ApoxiMakeCountryCode(H,N),  // HONDURAS
    CountryHK = ApoxiMakeCountryCode(H,K),  // HONG KONG
    CountryHU = ApoxiMakeCountryCode(H,U),  // HUNGARY
    CountryIS = ApoxiMakeCountryCode(I,S),  // ICELAND
    CountryIN = ApoxiMakeCountryCode(I,N),  // INDIA
    CountryID = ApoxiMakeCountryCode(I,D),  // INDONESIA
    CountryIR = ApoxiMakeCountryCode(I,R),  // IRAN (ISLAMIC REPUBLIC OF)
    CountryIQ = ApoxiMakeCountryCode(I,Q),  // IRAQ
    CountryIE = ApoxiMakeCountryCode(I,E),  // IRELAND
    CountryIL = ApoxiMakeCountryCode(I,L),  // ISRAEL
    CountryIT = ApoxiMakeCountryCode(I,T),  // ITALY
    CountryJM = ApoxiMakeCountryCode(J,M),  // JAMAICA
    CountryJP = ApoxiMakeCountryCode(J,P),  // JAPAN
    CountryJO = ApoxiMakeCountryCode(J,O),  // JORDAN
    CountryKZ = ApoxiMakeCountryCode(K,Z),  // KAZAKHSTAN
    CountryKE = ApoxiMakeCountryCode(K,E),  // KENYA
    CountryKI = ApoxiMakeCountryCode(K,I),  // KIRIBATI
    CountryKP = ApoxiMakeCountryCode(K,P),  // KOREA, DEMOCRATIC PEOPLE'S REPUBLIC OF
    CountryKR = ApoxiMakeCountryCode(K,R),  // KOREA, REPUBLIC OF
    CountryKW = ApoxiMakeCountryCode(K,W),  // KUWAIT
    CountryKG = ApoxiMakeCountryCode(K,G),  // KYRGYZSTAN
    CountryLA = ApoxiMakeCountryCode(L,A),  // LAO PEOPLE'S DEMOCRATIC REPUBLIC
    CountryLV = ApoxiMakeCountryCode(L,V),  // LATVIA
    CountryLB = ApoxiMakeCountryCode(L,B),  // LEBANON
    CountryLS = ApoxiMakeCountryCode(L,S),  // LESOTHO
    CountryLR = ApoxiMakeCountryCode(L,R),  // LIBERIA
    CountryLY = ApoxiMakeCountryCode(L,Y),  // LIBYAN ARAB JAMAHIRIYA
    CountryLI = ApoxiMakeCountryCode(L,I),  // LIECHTENSTEIN
    CountryLT = ApoxiMakeCountryCode(L,T),  // LITHUANIA
    CountryLU = ApoxiMakeCountryCode(L,U),  // LUXEMBOURG
    CountryMO = ApoxiMakeCountryCode(M,O),  // MACAU
    CountryMK = ApoxiMakeCountryCode(M,K),  // MACEDONIA, THE FORMER YUGOSLAV REPUBLIC OF
    CountryMG = ApoxiMakeCountryCode(M,G),  // MADAGASCAR
    CountryMW = ApoxiMakeCountryCode(M,W),  // MALAWI
    CountryMY = ApoxiMakeCountryCode(M,Y),  // MALAYSIA
    CountryMV = ApoxiMakeCountryCode(M,V),  // MALDIVES
    CountryML = ApoxiMakeCountryCode(M,L),  // MALI
    CountryMT = ApoxiMakeCountryCode(M,T),  // MALTA
    CountryMH = ApoxiMakeCountryCode(M,H),  // MARSHALL ISLANDS
    CountryMQ = ApoxiMakeCountryCode(M,Q),  // MARTINIQUE
    CountryMR = ApoxiMakeCountryCode(M,R),  // MAURITANIA
    CountryMU = ApoxiMakeCountryCode(M,U),  // MAURITIUS
    CountryYT = ApoxiMakeCountryCode(Y,T),  // MAYOTTE
    CountryMX = ApoxiMakeCountryCode(M,X),  // MEXICO
    CountryFM = ApoxiMakeCountryCode(F,M),  // MICRONESIA, FEDERATED STATES OF
    CountryMD = ApoxiMakeCountryCode(M,D),  // MOLDOVA, REPUBLIC OF
    CountryMC = ApoxiMakeCountryCode(M,C),  // MONACO
    CountryMN = ApoxiMakeCountryCode(M,N),  // MONGOLIA
    CountryMS = ApoxiMakeCountryCode(M,S),  // MONTSERRAT
    CountryMA = ApoxiMakeCountryCode(M,A),  // MOROCCO
    CountryMZ = ApoxiMakeCountryCode(M,Z),  // MOZAMBIQUE
    CountryMM = ApoxiMakeCountryCode(M,M),  // MYANMAR
    CountryNA = ApoxiMakeCountryCode(N,A),  // NAMIBIA
    CountryNR = ApoxiMakeCountryCode(N,R),  // NAURU
    CountryNP = ApoxiMakeCountryCode(N,P),  // NEPAL
    CountryNL = ApoxiMakeCountryCode(N,L),  // NETHERLANDS
    CountryAN = ApoxiMakeCountryCode(A,N),  // NETHERLANDS ANTILLES
    CountryNC = ApoxiMakeCountryCode(N,C),  // NEW CALEDONIA
    CountryNZ = ApoxiMakeCountryCode(N,Z),  // NEW ZEALAND
    CountryNI = ApoxiMakeCountryCode(N,I),  // NICARAGUA
    CountryNE = ApoxiMakeCountryCode(N,E),  // NIGER
    CountryNG = ApoxiMakeCountryCode(N,G),  // NIGERIA
    CountryNU = ApoxiMakeCountryCode(N,U),  // NIUE
    CountryNF = ApoxiMakeCountryCode(N,F),  // NORFOLK ISLAND
    CountryMP = ApoxiMakeCountryCode(M,P),  // NORTHERN MARIANA ISLANDS
    CountryNO = ApoxiMakeCountryCode(N,O),  // NORWAY
    CountryOM = ApoxiMakeCountryCode(O,M),  // OMAN
    CountryPK = ApoxiMakeCountryCode(P,K),  // PAKISTAN
    CountryPW = ApoxiMakeCountryCode(P,W),  // PALAU
    CountryPA = ApoxiMakeCountryCode(P,A),  // PANAMA
    CountryPG = ApoxiMakeCountryCode(P,G),  // PAPUA NEW GUINEA
    CountryPY = ApoxiMakeCountryCode(P,Y),  // PARAGUAY
    CountryPE = ApoxiMakeCountryCode(P,E),  // PERU
    CountryPH = ApoxiMakeCountryCode(P,H),  // PHILIPPINES
    CountryPN = ApoxiMakeCountryCode(P,N),  // PITCAIRN
    CountryPL = ApoxiMakeCountryCode(P,L),  // POLAND
    CountryPT = ApoxiMakeCountryCode(P,T),  // PORTUGAL
    CountryPR = ApoxiMakeCountryCode(P,R),  // PUERTO RICO
    CountryQA = ApoxiMakeCountryCode(Q,A),  // QATAR
    CountryRE = ApoxiMakeCountryCode(R,E),  // REUNION
    CountryRO = ApoxiMakeCountryCode(R,O),  // ROMANIA
    CountryRU = ApoxiMakeCountryCode(R,U),  // RUSSIAN FEDERATION
    CountryRW = ApoxiMakeCountryCode(R,W),  // RWANDA
    CountryKN = ApoxiMakeCountryCode(K,N),  // SAINT KITTS AND NEVIS
    CountryLC = ApoxiMakeCountryCode(L,C),  // SAINT LUCIA
    CountryVC = ApoxiMakeCountryCode(V,C),  // SAINT VINCENT AND THE GRENADINES
    CountryWS = ApoxiMakeCountryCode(W,S),  // SAMOA
    CountrySM = ApoxiMakeCountryCode(S,M),  // SAN MARINO
    CountryST = ApoxiMakeCountryCode(S,T),  // SAO TOME AND PRINCIPE
    CountrySA = ApoxiMakeCountryCode(S,A),  // SAUDI ARABIA
    CountrySN = ApoxiMakeCountryCode(S,N),  // SENEGAL
    CountrySC = ApoxiMakeCountryCode(S,C),  // SEYCHELLES
    CountrySL = ApoxiMakeCountryCode(S,L),  // SIERRA LEONE
    CountrySG = ApoxiMakeCountryCode(S,G),  // SINGAPORE
    CountrySK = ApoxiMakeCountryCode(S,K),  // SLOVAKIA (Slovak Republic)
    CountrySI = ApoxiMakeCountryCode(S,I),  // SLOVENIA
    CountrySB = ApoxiMakeCountryCode(S,B),  // SOLOMON ISLANDS
    CountrySO = ApoxiMakeCountryCode(S,O),  // SOMALIA
    CountryZA = ApoxiMakeCountryCode(Z,A),  // SOUTH AFRICA
    CountryGS = ApoxiMakeCountryCode(G,S),  // SOUTH GEORGIA AND THE SOUTH SANDWICH ISLANDS
    CountryES = ApoxiMakeCountryCode(E,S),  // SPAIN
    CountryLK = ApoxiMakeCountryCode(L,K),  // SRI LANKA
    CountrySH = ApoxiMakeCountryCode(S,H),  // ST. HELENA
    CountryPM = ApoxiMakeCountryCode(P,M),  // ST. PIERRE AND MIQUELON
    CountrySD = ApoxiMakeCountryCode(S,D),  // SUDAN
    CountrySR = ApoxiMakeCountryCode(S,R),  // SURINAME
    CountrySJ = ApoxiMakeCountryCode(S,J),  // SVALBARD AND JAN MAYEN ISLANDS
    CountrySZ = ApoxiMakeCountryCode(S,Z),  // SWAZILAND
    CountrySE = ApoxiMakeCountryCode(S,E),  // SWEDEN
    CountryCH = ApoxiMakeCountryCode(C,H),  // SWITZERLAND
    CountrySY = ApoxiMakeCountryCode(S,Y),  // SYRIAN ARAB REPUBLIC
    CountryTW = ApoxiMakeCountryCode(T,W),  // TAIWAN
    CountryTJ = ApoxiMakeCountryCode(T,J),  // TAJIKISTAN
    CountryTZ = ApoxiMakeCountryCode(T,Z),  // TANZANIA, UNITED REPUBLIC OF
    CountryTH = ApoxiMakeCountryCode(T,H),  // THAILAND
    CountryTG = ApoxiMakeCountryCode(T,G),  // TOGO
    CountryTK = ApoxiMakeCountryCode(T,K),  // TOKELAU
    CountryTO = ApoxiMakeCountryCode(T,O),  // TONGA
    CountryTT = ApoxiMakeCountryCode(T,T),  // TRINIDAD AND TOBAGO
    CountryTN = ApoxiMakeCountryCode(T,N),  // TUNISIA
    CountryTR = ApoxiMakeCountryCode(T,R),  // TURKEY
    CountryTM = ApoxiMakeCountryCode(T,M),  // TURKMENISTAN
    CountryTC = ApoxiMakeCountryCode(T,C),  // TURKS AND CAICOS ISLANDS
    CountryTV = ApoxiMakeCountryCode(T,V),  // TUVALU
    CountryUG = ApoxiMakeCountryCode(U,G),  // UGANDA
    CountryUA = ApoxiMakeCountryCode(U,A),  // UKRAINE
    CountryAE = ApoxiMakeCountryCode(A,E),  // UNITED ARAB EMIRATES
    CountryGB = ApoxiMakeCountryCode(G,B),  // UNITED KINGDOM
    CountryUS = ApoxiMakeCountryCode(U,S),  // UNITED STATES
    CountryUM = ApoxiMakeCountryCode(U,M),  // UNITED STATES MINOR OUTLYING ISLANDS
    CountryUY = ApoxiMakeCountryCode(U,Y),  // URUGUAY
    CountryUZ = ApoxiMakeCountryCode(U,Z),  // UZBEKISTAN
    CountryVU = ApoxiMakeCountryCode(V,U),  // VANUATU
    CountryVA = ApoxiMakeCountryCode(V,A),  // VATICAN CITY STATE (HOLY SEE)
    CountryVE = ApoxiMakeCountryCode(V,E),  // VENEZUELA
    CountryVN = ApoxiMakeCountryCode(V,N),  // VIET NAM
    CountryVG = ApoxiMakeCountryCode(V,G),  // VIRGIN ISLANDS (BRITISH)
    CountryVI = ApoxiMakeCountryCode(V,I),  // VIRGIN ISLANDS (U.S.)
    CountryWF = ApoxiMakeCountryCode(W,F),  // WALLIS AND FUTUNA ISLANDS
    CountryEH = ApoxiMakeCountryCode(E,H),  // WESTERN SAHARA
    CountryYE = ApoxiMakeCountryCode(Y,E),  // YEMEN
    CountryYU = ApoxiMakeCountryCode(Y,U),  // YUGOSLAVIA
    CountryZR = ApoxiMakeCountryCode(Z,R),  // ZAIRE
    CountryZM = ApoxiMakeCountryCode(Z,M),  // ZAMBIA
    CountryZW = ApoxiMakeCountryCode(Z,W),  // ZIMBABWE
    CountryInvalid = ApoxiMakeCountryCode(0,0)
};   // 239 countries generated

#endif // Apoxi_CountryCode_hpp


