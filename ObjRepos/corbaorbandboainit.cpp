[!outputon] // $Revision:   1.2  $
[!if=(ConsoleApp, "TRUE")]
	try
	{
[!if=(BOAInit, "TRUE")]
		// Initialize the ORB and BOA
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
		CORBA::BOA_var boa = orb->BOA_init(argc, argv);
[!else]
		// Initialize the ORB
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
[!endif]
[!if=(ImplIsReady, "TRUE")]
		// Wait for incoming requests 
		boa->impl_is_ready();
[!endif]
	}
	catch(const CORBA::Exception& e)
	{
		Cerr << e << endl;
		return(1);
	}
[!else]
[!if=(BOAInit, "TRUE")]
		// Initialize the ORB and BOA
		CORBA::ORB_var orb = CORBA::ORB_init(__argc, __argv);
		CORBA::BOA_var boa = orb->BOA_init(__argc, __argv);
[!else]
		// Initialize the ORB
		CORBA::ORB_var orb = CORBA::ORB_init(__argc, __argv);
[!endif]
[!endif]

