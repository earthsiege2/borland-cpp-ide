#pragma option push -b -a8 -pc -A- /*P_O_Push*/

struct MyCatId : public CATID
{
	inline MyCatId(const CATID &catid) {memcpy((CATID *) this, &catid, sizeof(CATID));}
};
#pragma option pop /*P_O_Pop*/
