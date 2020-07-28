void setup() 
{
  Serial.begin(115200);// put your setup code here, to run once:

}

void loop() 
{
  Serial.println("hello");// put your main code here, to run repeatedly:
  Serial.write("hello");
}
