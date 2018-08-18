/*
 * This Arduino program is used to find the right value for the calibration_ratio
 * 
 * Datasheet of the HX711 chip:
 * https://cdn.sparkfun.com/datasheets/Sensors/ForceFlex/hx711_english.pdf
 */

const uint8_t pin_dout = A1; // Data Out Pin
const uint8_t pin_sck = A0; // Serial Clock Pin

const byte REPETITIONS = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(averageValue(REPETITIONS));
  delay(200);
}

long averageValue(byte times)
{
	long sum = 0;
	for (byte i = 0; i < times; i++)
	{
		sum += getValue();
	}

	return sum / times;
}

long getValue()
{
	byte data[3];

  // wait until there is data on DOUT
	while (digitalRead(pin_dout))
		;

  // read the 24 bits from DOUT
  // starting with the most significant bit
	for (int j = 2; j>=0; j--)
	{
		for (char i = 7; i>=0; i--)
		{
			digitalWrite(pin_sck, HIGH);
			bitWrite(data[j], i, digitalRead(pin_dout));
			digitalWrite(pin_sck, LOW);
		}
	}

  // set DOUT of the chip back to high
	digitalWrite(pin_sck, HIGH);
	digitalWrite(pin_sck, LOW);

  // the hx711 sends 0x80 for MIN value
  // in this case we set data to 0
	data[2] ^= 0x80;

	return ((uint32_t) data[2] << 16) | ((uint32_t) data[1] << 8)
			| (uint32_t) data[0];
}