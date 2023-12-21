float tempRead(float ntcRead);

float tempRead(float ntcRead) {
  //define here how many bits you adc reads, and the normal voltage of your controller
  float adcbitsize = 4096.0, adcvoltagrange = 3.3; //esp32 (may differ, its possible to change the bit range of the read)
  double Raux = 10000.0, Rd0 = 10000.0, T_0 = 298.15, Vadc = 0.0, Rntc = 0.0, T_1 = 273.15, T_2 = 373.15,
         RT1 = 35563.0, RT2 = 549.4, beta = 0.0, Rinf = 0.0, tempK = 0.0, npi = 3.14159265358979323846;

  Vadc = (adcvoltagrange * ntcRead) / adcbitsize;
  Rntc = (Raux * Vadc / (adcvoltagrange - Vadc));
  tempK = (beta / log(Rntc / Rinf));
  return tempK - 273.15;
}