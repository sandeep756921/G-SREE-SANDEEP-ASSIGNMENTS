int unitsPins[4] = {2, 3, 4, 5};
int tensPins[2] = {6, 7};
void setup()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(unitsPins[i], OUTPUT);
  }

  for (int i = 0; i < 2; i++)
  {
    pinMode(tensPins[i], OUTPUT);
  }
}
void showNumber(int num)
{
  int tens = num / 10;
  int units = num % 10;

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(unitsPins[i], (units >> i) & 1);
  }

  for (int i = 0; i < 2; i++)
  {
    digitalWrite(tensPins[i], (tens >> i) & 1);
  }
}

void loop()
{
  for (int n = 0; n <= 30; n++)
  {
    showNumber(n);
    delay(1000);
  }
}
