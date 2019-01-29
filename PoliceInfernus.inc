#if defined POLICEINFERNUS
	#endinput
#endif
#define POLICEINFERNUS

#if !defined INFERNUS
	#define INFERNUS	411
#endif

static
	police_infernus[MAX_VEHICLES][10] = {INVALID_OBJECT_ID, ...};

stock CreatePoliceInfernus(Float:x, Float:y, Float:z, Float:a, respawn = 0)
{
	static
		vehicleid,
		objectid;

	vehicleid = CreateVehicle(INFERNUS, x, y, z, a, 0, 0, respawn, 1);

	objectid = CreateDynamicObject(19476, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000);
	SetDynamicObjectMaterialText(objectid, 0, !"POLICE", 120, !"Arial", 100, 1, -1, 0, 1);
	AttachDynamicObjectToVehicle(objectid, vehicleid, -0.001276, 2.790166, -0.456286, 0.000000, 21.799999, 90.000000);
	police_infernus[vehicleid][0] = objectid;

	objectid = CreateDynamicObject(19477, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000); //+1
	SetDynamicObjectMaterialText(objectid, 0, !"POLICE", 130, !"Arial", 60, 1, -1, 0, 1);
	AttachDynamicObjectToVehicle(objectid, vehicleid, 0.001995, -1.970654, 0.239949, 0.000000, -85.200073, -90.000000);
	police_infernus[vehicleid][1] = objectid;

	objectid = CreateDynamicObject(19797, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000); //+2
	AttachDynamicObjectToVehicle(objectid, vehicleid, -0.623635, 2.719873, -0.489997, 197.100002, 0.000000, -168.299880);
	police_infernus[vehicleid][2] = objectid;
	objectid = CreateDynamicObject( 19797, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000);//+3
	AttachDynamicObjectToVehicle(objectid, vehicleid, 0.623635, 2.719873, -0.489997, 197.100002, 0.000000, 168.299880);
	police_infernus[vehicleid][3] = objectid;

	objectid = CreateDynamicObject(19797, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000); //+4
	AttachDynamicObjectToVehicle(objectid, vehicleid, -0.778895, -2.520503, -0.455543, 202.600015, 0.000000, -4.399932);
	police_infernus[vehicleid][4] = objectid;
	objectid = CreateDynamicObject(19797, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000); //+5
	AttachDynamicObjectToVehicle(objectid, vehicleid, 0.778895, -2.520503, -0.455543, 202.600015, 0.000000, 4.399932);
	police_infernus[vehicleid][5] = objectid;

	objectid = CreateDynamicObject(19620, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000); //+2
	SetDynamicObjectMaterial(objectid, 0, 19620, !"LightBar1", !"lightbar1", 0xFFFFFFFF);
	AttachDynamicObjectToVehicle(objectid, vehicleid, -0.000567, 0.159840, 0.709995, 0.000000, 0.000000, 0.000000);
	police_infernus[vehicleid][6] = objectid;

	return vehicleid;

}

public OnVehicleSirenStateChange(playerid, vehicleid, newstate)
{
	if (police_infernus[vehicleid][0] != INVALID_OBJECT_ID)
	{
		if (newstate) 
		{
			static
				objectid;

			AttachDynamicObjectToVehicle(police_infernus[vehicleid][2], vehicleid, -0.623635, 2.719873, -0.489997, 17.100002, 0.000000, -168.299880);
			AttachDynamicObjectToVehicle(police_infernus[vehicleid][3], vehicleid, 0.623635, 2.719873, -0.489997, 17.100002, 0.000000, 168.299880);
			AttachDynamicObjectToVehicle(police_infernus[vehicleid][4], vehicleid, -0.778895, -2.520503, -0.455543, 22.600015, 0.000000, -4.399932);
			AttachDynamicObjectToVehicle(police_infernus[vehicleid][5], vehicleid, 0.778895, -2.520503, -0.455543, 22.600015, 0.000000, 4.399932);

			DestroyDynamicObject(police_infernus[vehicleid][6]);
			police_infernus[vehicleid][6] = CreateDynamicObject(19620, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000);
			AttachDynamicObjectToVehicle(police_infernus[vehicleid][6], vehicleid, -0.000567, 0.159840, 0.709995, 0.000000, 0.000000, 0.000000);

			objectid = CreateDynamicObject(19419, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000);
			SetDynamicObjectMaterialText(objectid, 0, !"_", 130, !"Arial", 60, 0, 0, 0, 1);
			AttachDynamicObjectToVehicle(objectid, vehicleid, -0.000567, 0.159840, 0.709995, 0.000000, 0.000000, 180.000000);
			police_infernus[vehicleid][7] = objectid;
			objectid = CreateDynamicObject(19419, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000);
			SetDynamicObjectMaterialText(objectid, 0, !"_", 130, !"Arial", 60, 0, 0, 0, 1);
			AttachDynamicObjectToVehicle(objectid, vehicleid, 0.000273, 2.820966, -0.900011, 0.000000, 0.000000, 180.0000);
			police_infernus[vehicleid][8] = objectid;
			objectid = CreateDynamicObject(19419, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000);
			SetDynamicObjectMaterialText(objectid, 0, !"_", 130, !"Arial", 60, 0, 0, 0, 1);
			AttachDynamicObjectToVehicle(objectid, vehicleid, 0.000558, -2.637919, -0.900011, 0.000000, 0.000000, 180.0000);
			police_infernus[vehicleid][9] = objectid;

			Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
		}
		else 
		{
			PoliceInfernusToOff(vehicleid);
		}
	}

	#if  defined pi_OnVehicleSirenStateChange
		pi_OnVehicleSirenStateChange(playerid, vehicleid, newstate);
	#endif

	return 1;
}

#if defined _ALS_OnVehicleSirenStateChange
	#undef	OnVehicleSirenStateChange
#else
	#define	_ALS_OnVehicleSirenStateChange
#endif
#define OnVehicleSirenStateChange	pi_OnVehicleSirenStateChange
#if defined pi_OnVehicleSirenStateChange
	forward pi_OnVehicleSirenStateChange(playerid, vehicleid, newstate);
#endif

public OnVehicleDeath(vehicleid, killerid)
{
	PoliceInfernusToOff(vehicleid);
	
	#if  defined pi_OnVehicleDeath
		pi_OnVehicleDeath(vehicleid, killerid);
	#endif

	return 1;
}

#if defined _ALS_OnVehicleDeath
	#undef  OnVehicleDeath
#else
	#define _ALS_OnVehicleDeath
#endif
#define OnVehicleDeath  pi_OnVehicleDeath
#if defined pi_OnVehicleDeath
	forward pi_OnVehicleDeath(vehicleid, killerid);
#endif

static stock PoliceInfernusToOff(vehicleid)
{
	AttachDynamicObjectToVehicle(police_infernus[vehicleid][2], vehicleid, -0.623635, 2.719873, -0.489997, 197.100002, 0.000000, -168.299880);
	AttachDynamicObjectToVehicle(police_infernus[vehicleid][3], vehicleid, 0.623635, 2.719873, -0.489997, 197.100002, 0.000000, 168.299880);
	AttachDynamicObjectToVehicle(police_infernus[vehicleid][4], vehicleid, -0.778895, -2.520503, -0.455543, 202.600015, 0.000000, -4.399932);
	AttachDynamicObjectToVehicle(police_infernus[vehicleid][5], vehicleid, 0.778895, -2.520503, -0.455543, 202.600015, 0.000000, 4.399932);

	SetDynamicObjectMaterial(police_infernus[vehicleid][6], 0, 19620, !"LightBar1", !"lightbar1", 0xFFFFFFFF);

	DestroyDynamicObject(police_infernus[vehicleid][7]);
	DestroyDynamicObject(police_infernus[vehicleid][8]);
	DestroyDynamicObject(police_infernus[vehicleid][9]);

	return 1;
}

stock DestroyPoliceInfernus(vehicleid)
{
	DestroyVehicle(vehicleid);

	DestroyDynamicObject(police_infernus[vehicleid][0]);
	DestroyDynamicObject(police_infernus[vehicleid][1]);
	DestroyDynamicObject(police_infernus[vehicleid][2]);
	DestroyDynamicObject(police_infernus[vehicleid][3]);
	DestroyDynamicObject(police_infernus[vehicleid][4]);
	DestroyDynamicObject(police_infernus[vehicleid][5]);
	DestroyDynamicObject(police_infernus[vehicleid][6]);
	DestroyDynamicObject(police_infernus[vehicleid][7]);
	DestroyDynamicObject(police_infernus[vehicleid][8]);
	DestroyDynamicObject(police_infernus[vehicleid][9]);

	police_infernus[vehicleid][pi_police] = false;

	return 1;
}

//by m1n1vv
