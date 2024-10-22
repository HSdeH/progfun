function exp(a:nat, e:nat): nat {
    if e==0 then 1 else a*exp(a,e-1)
}

function fastExp(a:nat, e:nat): nat 
{
  if e==0 then 1
  else if e%2==0 
       then fastExp(a*a, e/2)
       else a*fastExp(a, e-1)         
}

lemma equalExp(a: nat, e: nat)
ensures exp(a,e) == fastExp(a,e)
{
  // 'implement' this proof
}
