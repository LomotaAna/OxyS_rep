enum State_enum {Relanti, CNP, Masurare, Alerta, Salvare_24};
enum Senzor_enum {NONE, Sensor_puls, ecran, BOTH};

void state_machine_run(uint8_t senzor);
void introdu_CNP();
void salveaza_CNP();
void masoara_puls(); // le facem float
void input_user();
void masoara_sat(); // float
void notificare_alerta();
void user_nou() ;// 
void timp_24h();
void salveaza();
uint8_t read_IR();

uint8_t state= Relanti;



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  state_machine_run(read_IR());
  delay(10);

}
void state_machine_run(uint8_t senzor)
{
  switch(state)
  {
    case Relanti:
      if(senzor==NONE){
      //
      }
    break;

    case CNP:
    if(senzor==ecran){
      introdu_CNP();
      salveaza_CNP(); 
      }
    break;
    
    case Masurare:
      if(senzor==Senzor_puls){
        masoara_puls();
        masoara_sat();
      }
     break;

     case Alerta:
        if(senzor==Senzor_puls){
          if(masoara_sat<=95 || masoara_puls>=150|| masoara_puls<=50){
            notificare_alerta();
           }
         }
      break;

      case Salvare_24:
         if(timp_24==24){
          salveaza();
         }
         break;   
  }
}
//def functii
