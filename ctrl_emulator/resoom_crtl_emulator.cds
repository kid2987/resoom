<distribution version="15.0.1" name="resoom_crtl_emulator" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{BF1A4D21-B51D-460E-9D24-64867E651E43}">
		<general appName="resoom_crtl_emulator" outputLocation="e:\c_works\resoom\ctrl_emulator\cvidistkit.resoom_crtl_emulator" relOutputLocation="cvidistkit.resoom_crtl_emulator" outputLocationWithVars="e:\c_works\resoom\ctrl_emulator\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.1">
			<arp company="gustaf" companyURL="" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="English" showPaths="true" showRuntimeOnly="true" readMe="" license="">
			<dlgstrings welcomeTitle="resoom_crtl_emulator" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="resoom_crtl_emulator" dirID="100" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="resoom_crtl_emulator" dirID="101" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/></dirs>
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
		<Projects NumProjects="0"/>
		<buildData progressBarRate="4.615439716634157">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.131086500000000</ProductsAdded>
				<DPConfigured>1.106086500000000</DPConfigured>
				<DPMergeModulesAdded>3.436085999999997</DPMergeModulesAdded>
				<DPClosed>11.836086000000000</DPClosed>
				<DistributionsCopied>12.386208999999996</DistributionsCopied>
				<End>21.666407999999993</End></progressTimes></buildData>
	</msi>
</distribution>
