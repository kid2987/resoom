<distribution version="15.0.1" name="resoom_crtl_emulator" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{BF1A4D21-B51D-460E-9D24-64867E651E43}">
		<general appName="resoom_crtl_emulator" outputLocation="e:\c_works\resoom\ctrl_emulator\cvidistkit.resoom_crtl_emulator" relOutputLocation="cvidistkit.resoom_crtl_emulator" outputLocationWithVars="e:\c_works\resoom\ctrl_emulator\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.0">
			<arp company="gustaf" companyURL="" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="English" showPaths="true" showRuntimeOnly="true" readMe="" license="">
			<dlgstrings welcomeTitle="resoom_crtl_emulator" welcomeText=""/></userinterface>
		<dirs appDirID="101">
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="resoom_crtl_emulator" dirID="100" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="resoom_crtl_emulator" dirID="101" parentID="2" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="e:\c_works\resoom\ctrl_emulator\cvibuild.Reader_control\Release\Reader_control.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="101" projectID="0">
				<fileID>0</fileID></projectOutput>
			<projectDependencies dirID="101" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="resoom_crtl_emulator" targetFileID="0" destDirID="100" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine installToAppDir="false" activeXsup="true" analysis="true" cvirte="true" dotnetsup="true" instrsup="false" lowlevelsup="true" lvrt="false" netvarsup="true" rtutilsup="true">
			<hasSoftDeps/></runtimeEngine><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WIN7_SP1</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<baselineProducts/>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="e:\c_works\resoom\ctrl_emulator\Reader_control.prj" ProjectRelativePath="Reader_control.prj"/></Projects>
	</msi>
</distribution>
