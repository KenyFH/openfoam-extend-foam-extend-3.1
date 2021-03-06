// ignore special fields or fields that we don't handle
//
bool variableGood = true;
for (label n1=startTime; n1<endTime && variableGood; ++n1)
{
    // ignore _0 fields
    if (fieldName.size() > 2 && fieldName(fieldName.size() - 2, 2) == "_0")
    {
        variableGood = false;
    }
    else
    {
        variableGood = IOobject
        (
            fieldName,
            Times[n1].name(),
            mesh,
            IOobject::NO_READ
        ).headerOk();
    }
}
