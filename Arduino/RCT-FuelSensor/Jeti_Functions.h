//
// For any extra functions needed before loop()
//
void flowTick()
{
  count_raw++;
}

void(* resetFunc) (void) = 0;
