import gs from "gs_napi";

export default class MainAbility extends Ability {
  onCreate() {
    super.onCreate();
    const code = gs.convert("/data/app/test.pdf", "/data/app/out.pclm");
    console.info("convert result:", code);
  }
}
